#include <iostream>
#include <cmath>
using namespace std;

// Структура Pair (пара)
struct Pair {
    double first;  // цена товара
    int second;    // количество единиц

    // Метод инициализации
    void init(double price, int quantity) {
        if (price <= 0 || quantity <= 0) {
            cout << "Ошибка: цена и количество должны быть положительными." << endl;
            exit(1);
        }
        first = price;
        second = quantity;
    }

    // Ввод с клавиатуры
    void read() {
        cout << "Введите цену товара (дробное положительное число): ";
        cin >> first;
        cout << "Введите количество единиц (целое положительное число): ";
        cin >> second;
        if (first <= 0 || second <= 0) {
            cout << "Ошибка: недопустимые значения." << endl;
            exit(1);
        }
    }

    // Вывод на экран
    void display() const {
        cout << "Цена: " << first << ", Количество: " << second << endl;
    }

    // Вычисление стоимости
    double cost() const {
        return first * second;
    }
};

// Внешняя функция для создания структуры
Pair make_Pair(double price, int quantity) {
    if (price <= 0 || quantity <= 0) {
        cout << "Ошибка в make_Pair: недопустимые аргументы." << endl;
        exit(1);
    }
    Pair p;
    p.first = price;
    p.second = quantity;
    return p;
}

int main() {
    // Демонстрация различных способов создания объектов
    Pair p1;               // создание без инициализации
    p1.init(150.75, 3);    // инициализация методом init
    cout << "p1: ";
    p1.display();
    cout << "Стоимость p1: " << p1.cost() << endl;

    Pair p2;               // ввод с клавиатуры
    p2.read();
    cout << "p2: ";
    p2.display();
    cout << "Стоимость p2: " << p2.cost() << endl;

    Pair p3 = make_Pair(299.99, 2);  // создание через внешнюю функцию
    cout << "p3: ";
    p3.display();
    cout << "Стоимость p3: " << p3.cost() << endl;

    // Массив объектов
    Pair arr[2];
    arr[0].init(50.5, 10);
    arr[1].init(100.0, 5);

    cout << "\nМассив пар:" << endl;
    for (int i = 0; i < 2; i++) {
        arr[i].display();
        cout << "Стоимость: " << arr[i].cost() << endl;
    }

    return 0;
}
