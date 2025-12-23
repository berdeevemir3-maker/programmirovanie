#include <iostream>
#include <cstring>
using namespace std;

// Базовый класс Array (из методички)
class Array {
protected:
    static const int MAX = 100;
    unsigned char* data;
    int size;
public:
    Array() : data(nullptr), size(0) {}
    Array(int n, unsigned char init = 0) : size(n) {
        if (n <= 0 || n > MAX) {
            cerr << "Недопустимый размер массива.\n";
            exit(1);
        }
        data = new unsigned char[n];
        for (int i = 0; i < n; i++) data[i] = init;
    }
    virtual ~Array() { delete[] data; }

    int getSize() const { return size; }

    unsigned char& operator[](int index) {
        if (index < 0 || index >= size) {
            cerr << "Выход за границы массива.\n";
            exit(1);
        }
        return data[index];
    }

    // Виртуальный метод поэлементного сложения
    virtual Array* add(Array& other) {
        cout << "Array::add\n";
        int maxSize = (size > other.size) ? size : other.size;
        Array* result = new Array(maxSize);
        for (int i = 0; i < maxSize; i++) {
            unsigned char a = (i < size) ? data[i] : 0;
            unsigned char b = (i < other.size) ? other.data[i] : 0;
            (*result)[i] = a + b;
        }
        return result;
    }

    virtual void print() const {
        for (int i = 0; i < size; i++) cout << (int)data[i] << " ";
        cout << endl;
    }
};

// Класс Decimal (знаковый десятичный)
class Decimal : public Array {
private:
    bool sign; // true = отрицательный
public:
    Decimal() : Array(), sign(false) {}
    Decimal(int n, bool s = false, unsigned char init = 0) : Array(n, init), sign(s) {}

    bool getSign() const { return sign; }
    void setSign(bool s) { sign = s; }

    // Переопределение виртуального метода
    Array* add(Array& other) override {
        cout << "Decimal::add (десятичное сложение)\n";
        // Для простоты считаем, что other тоже Decimal
        Decimal& decOther = dynamic_cast<Decimal&>(other);
        int maxSize = (size > decOther.size) ? size : decOther.size;
        Decimal* result = new Decimal(maxSize);
        int carry = 0;
        for (int i = 0; i < maxSize; i++) {
            int a = (i < size) ? data[i] : 0;
            int b = (i < decOther.size) ? decOther.data[i] : 0;
            int sum = a + b + carry;
            (*result)[i] = sum % 10;
            carry = sum / 10;
        }
        if (carry) {
            // Упрощённо — расширяем массив
            cout << "Переполнение в Decimal сложении.\n";
        }
        result->sign = (sign && decOther.sign); // упрощённая логика знака
        return result;
    }

    void print() const override {
        if (sign) cout << "-";
        for (int i = size - 1; i >= 0; i--) cout << (int)data[i];
        cout << " (Decimal)";
    }
};

// Класс BitString (битовая строка)
class BitString : public Array {
public:
    BitString() : Array() {}
    BitString(int n, unsigned char init = 0) : Array(n, init) {
        // Инициализация только 0/1
        for (int i = 0; i < n; i++) data[i] = (init > 0) ? 1 : 0;
    }

    // Переопределение виртуального метода
    Array* add(Array& other) override {
        cout << "BitString::add (побитовое XOR)\n";
        int maxSize = (size > other.size) ? size : other.size;
        BitString* result = new BitString(maxSize);
        for (int i = 0; i < maxSize; i++) {
            unsigned char a = (i < size) ? data[i] : 0;
            unsigned char b = (i < other.size) ? other.data[i] : 0;
            (*result)[i] = a ^ b; // XOR как пример операции
        }
        return result;
    }

    void print() const override {
        for (int i = size - 1; i >= 0; i--) cout << (int)(data[i] & 1);
        cout << " (BitString)";
    }
};

int main() {
    // 1. Создание объектов разных классов
    Decimal d1(5, false);
    d1[0] = 3; d1[1] = 2; d1[2] = 1; // число 123
    cout << "d1 = "; d1.print(); cout << endl;

    Decimal d2(4, false);
    d2[0] = 7; d2[1] = 8; // число 87
    cout << "d2 = "; d2.print(); cout << endl;

    BitString b1(4, 1);
b1[0] = 0; b1[1] = 1; b1[2] = 0; b1[3] = 1; // 1010
    cout << "b1 = "; b1.print(); cout << endl;

    BitString b2(3, 1);
    b2[0] = 1; b2[1] = 1; // 110
    cout << "b2 = "; b2.print(); cout << endl;

    // 2. Вызов виртуальных методов через указатель на базовый класс
    Array* arrs[4];
    arrs[0] = &d1;
    arrs[1] = &d2;
    arrs[2] = &b1;
    arrs[3] = &b2;

    cout << "\nДемонстрация виртуальных вызовов:\n";
    for (int i = 0; i < 4; i++) {
        arrs[i]->print();
        cout << endl;
    }

    // 3. Сложение объектов одного типа (виртуальный вызов)
    cout << "\nСложение d1 и d2:\n";
    Array* sumDec = arrs[0]->add(*arrs[1]);
    sumDec->print();
    delete sumDec;

    cout << "\n\nСложение b1 и b2:\n";
    Array* sumBits = arrs[2]->add(*arrs[3]);
    sumBits->print();
    delete sumBits;

    cout << "\n\nПопытка сложения разнотипных объектов (Decimal + BitString):\n";
    // Вызовется метод того класса, на который указывает указатель
    Array* mix = arrs[0]->add(*arrs[2]); // Decimal::add
    mix->print();
    delete mix;

    return 0;
}
