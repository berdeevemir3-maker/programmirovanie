#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Man {
protected:
    string name;
    int age;
    char gender; // 'M' или 'F'
    double weight;
public:
    // Конструкторы
    Man() : name("Unknown"), age(0), gender('M'), weight(0.0) {}
    Man(string n, int a, char g, double w) {
        setName(n);
        setAge(a);
        setGender(g);
        setWeight(w);
    }

    // Методы изменения полей с проверкой
    void setName(string n) {
        if (n.empty()) {
            cerr << "Имя не может быть пустым.\n";
            exit(1);
        }
        name = n;
    }

    void setAge(int a) {
        if (a < 0 || a > 150) {
            cerr << "Недопустимый возраст.\n";
            exit(1);
        }
        age = a;
    }

    void setGender(char g) {
        if (g != 'M' && g != 'F') {
            cerr << "Пол должен быть 'M' или 'F'.\n";
            exit(1);
        }
        gender = g;
    }

    void setWeight(double w) {
        if (w <= 0 || w > 500) {
            cerr << "Недопустимый вес.\n";
            exit(1);
        }
        weight = w;
    }

    // Методы получения значений
    string getName() const { return name; }
    int getAge() const { return age; }
    char getGender() const { return gender; }
    double getWeight() const { return weight; }

    // Вывод информации
    virtual void display() const {
        cout << "Имя: " << name << ", Возраст: " << age
             << ", Пол: " << gender << ", Вес: " << weight << " кг\n";
    }

    // Преобразование в строку
    virtual string toString() const {
        return "Человек: " + name + ", " + to_string(age) + " лет, " +
               string(1, gender) + ", " + to_string(weight) + " кг";
    }
};

class Student : public Man {
private:
    int yearOfStudy; // год обучения (1-6, например)
public:
    Student() : Man(), yearOfStudy(1) {}
    Student(string n, int a, char g, double w, int y) : Man(n, a, g, w) {
        setYear(y);
    }

    void setYear(int y) {
        if (y < 1 || y > 10) {
            cerr << "Недопустимый год обучения.\n";
            exit(1);
        }
        yearOfStudy = y;
    }

    int getYear() const { return yearOfStudy; }

    void increaseYear() {
        if (yearOfStudy < 10) yearOfStudy++;
        else cout << "Максимальный год обучения достигнут.\n";
    }

    void display() const override {
        Man::display();
        cout << "Год обучения: " << yearOfStudy << "\n";
    }

    string toString() const override {
        return Man::toString() + ", Год обучения: " + to_string(yearOfStudy);
    }
};

int main() {
    // 1. Создание объектов базового класса
    Man m1("Иван", 25, 'M', 75.5);
    cout << "m1: " << m1.toString() << endl;

    // 2. Создание объектов производного класса
    Student s1("Анна", 20, 'F', 55.0, 3);
    cout << "s1: " << s1.toString() << endl;

    // 3. Принцип подстановки (объект производного класса в указатель базового)
    Man* ptr = &s1;
    cout << "Через указатель на Man: " << ptr->toString() << endl;

    // 4. Массив объектов (смешанный)
    Man* people[3];
    people[0] = new Man("Петр", 30, 'M', 80.0);
    people[1] = new Student("Мария", 22, 'F', 60.0, 4);
    people[2] = new Student("Сергей", 19, 'M', 70.0, 2);

    cout << "\nМассив людей:\n";
    for (int i = 0; i < 3; i++) {
        people[i]->display();
        cout << "---\n";
    }

    // 5. Изменение полей
    s1.setAge(21);
    s1.increaseYear();
    cout << "\nПосле изменений:\n" << s1.toString() << endl;

    // 6. Освобождение памяти
    for (int i = 0; i < 3; i++) delete people[i];

    return 0;
}
