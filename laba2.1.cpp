#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Triangle {
private:
    double a, b, c; // стороны
    double A, B, C; // углы в градусах

    // Вспомогательные методы
    void computeAngles() {
        // По теореме косинусов
        A = acos((b*b + c*c - a*a) / (2*b*c)) * 180 / M_PI;
        B = acos((a*a + c*c - b*b) / (2*a*c)) * 180 / M_PI;
        C = 180 - A - B;
    }

    bool isValid(double s1, double s2, double s3) {
        return (s1 > 0 && s2 > 0 && s3 > 0 &&
                s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1);
    }

public:
    // Конструктор без аргументов
    Triangle() : a(3), b(4), c(5) {
        computeAngles();
    }

    // Конструктор инициализации по сторонам
    Triangle(double side1, double side2, double side3) {
        if (!isValid(side1, side2, side3)) {
            cerr << "Ошибка: недопустимые стороны треугольника.\n";
            exit(1);
        }
        a = side1; b = side2; c = side3;
        computeAngles();
    }

    // Конструктор копирования
    Triangle(const Triangle& other) {
        a = other.a; b = other.b; c = other.c;
        A = other.A; B = other.B; C = other.C;
    }

    // Методы доступа
    void setSides(double s1, double s2, double s3) {
        if (!isValid(s1, s2, s3)) {
            cerr << "Ошибка: недопустимые стороны.\n";
            return;
        }
        a = s1; b = s2; c = s3;
        computeAngles();
    }

    void getSides(double& s1, double& s2, double& s3) const {
        s1 = a; s2 = b; s3 = c;
    }

    void getAngles(double& ang1, double& ang2, double& ang3) const {
        ang1 = A; ang2 = B; ang3 = C;
    }

    // Вычисление периметра
    double perimeter() const {
        return a + b + c;
    }

    // Вычисление площади по формуле Герона
    double area() const {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    // Высота к стороне a
    double height(char side) const {
        double ar = area();
        if (side == 'a') return 2 * ar / a;
        if (side == 'b') return 2 * ar / b;
        if (side == 'c') return 2 * ar / c;
        return 0;
    }

    // Определение вида треугольника
    string type() const {
        if (a == b && b == c) return "Равносторонний";
        if (a == b  b == c  a == c) return "Равнобедренный";
        // Проверка на прямоугольный (погрешность 0.1 градуса)
        if (fabs(A - 90) < 0.1  fabs(B - 90) < 0.1  fabs(C - 90) < 0.1)
            return "Прямоугольный";
        return "Разносторонний";
    }

    // Вывод информации
    void display() const {
        cout << "Стороны: " << a << ", " << b << ", " << c << endl;
        cout << "Углы: " << A << ", " << B << ", " << C << " градусов" << endl;
        cout << "Периметр: " << perimeter() << endl;
        cout << "Площадь: " << area() << endl;
        cout << "Тип: " << type() << endl;
    }
};

int main() {
    // 1. Конструктор без аргументов
    Triangle t1;
    cout << "t1 (по умолчанию):\n";
    t1.display();

    // 2. Конструктор инициализации
    Triangle t2(5, 5, 5);
    cout << "\nt2 (5,5,5):\n";
    t2.display();

    // 3. Конструктор копирования
    Triangle t3(t2);
    cout << "\nt3 (копия t2):\n";
    t3.display();

    // 4. Изменение полей
    t1.setSides(6, 8, 10);
    cout << "\nt1 после изменения сторон (6,8,10):\n";
    t1.display();

    // 5. Массив объектов
    Triangle arr[3] = { Triangle(3,4,5), Triangle(5,12,13), Triangle(7,7,7) };
    cout << "\nМассив треугольников:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Треугольник " << i+1 << ":\n";
        arr[i].display();
        cout << "Высота к стороне 'a': " << arr[i].height('a') << "\n\n";
    }

    return 0;
}
