#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Triangle {
private:
    double a, b, c; // стороны треугольника

    // Проверка корректности сторон
    bool isValid(double s1, double s2, double s3) const {
        return (s1 > 0 && s2 > 0 && s3 > 0 &&
                s1 + s2 > s3 && s1 + s3 > s2 && s2 + s3 > s1);
    }

    // Вычисление углов (вспомогательный метод)
    void computeAngles(double& A, double& B, double& C) const {
        A = acos((b*b + c*c - a*a) / (2*b*c)) * 180 / M_PI;
        B = acos((a*a + c*c - b*b) / (2*a*c)) * 180 / M_PI;
        C = 180 - A - B;
    }

public:
    // Конструкторы
    Triangle() : a(3), b(4), c(5) {} // конструктор без аргументов
    Triangle(double s1, double s2, double s3) {
        if (!isValid(s1, s2, s3)) {
            cerr << "Ошибка: недопустимые стороны треугольника.\n";
            exit(1);
        }
        a = s1; b = s2; c = s3;
    }

    // Методы доступа
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    void setSides(double s1, double s2, double s3) {
        if (!isValid(s1, s2, s3)) {
            cerr << "Ошибка: недопустимые стороны.\n";
            return;
        }
        a = s1; b = s2; c = s3;
    }

    // Периметр
    double perimeter() const {
        return a + b + c;
    }

    // Площадь по формуле Герона
    double area() const {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    // Определение вида треугольника
    string type() const {
        if (a == b && b == c) return "Равносторонний";
        if (a == b || b == c || a == c) return "Равнобедренный";
        double A, B, C;
        computeAngles(A, B, C);
        if (fabs(A - 90) < 0.1uble a, b, c; // стороны тfabs(C - 90) < 0.1)
            return "Прямоугольный";
        return "Разносторонний";
    }

    // ---------- ПЕРЕГРУЗКА ОПЕРАЦИЙ ----------

    // Сложение треугольников (сумма соответствующих сторон)
    Triangle operator+(const Triangle& other) const {
        return Triangle(a + other.a, b + other.b, c + other.c);
    }

    // Вычитание треугольников (разность сторон)
    Triangle operator-(const Triangle& other) const {
        return Triangle(a - other.a, b - other.b, c - other.c);
    }

    // Умножение на скаляр (масштабирование)
    Triangle operator*(double scalar) const {
        return Triangle(a * scalar, b * scalar, c * scalar);
    }

    // Деление на скаляр
    Triangle operator/(double scalar) const {
        if (fabs(scalar) < 1e-10) {
            cerr << "Ошибка: деление на ноль.\n";
            return *this;
        }
        return Triangle(a / scalar, b / scalar, c / scalar);
    }

    // Унарный минус (отражение? условная операция)
    Triangle operator-() const {
        return Triangle(-a, -b, -c);
    }

    // Операции сравнения по площади
    bool operator==(const Triangle& other) const {
        return fabs(area() - other.area()) < 1e-6;
    }

    bool operator!=(const Triangle& other) const {
        return !(*this == other);
    }

    bool operator>(const Triangle& other) const {
        return area() > other.area();
    }

    bool operator<(const Triangle& other) const {
        return area() < other.area();
    }

    bool operator>=(const Triangle& other) const {
        return area() >= other.area();
    }

    bool operator<=(const Triangle& other) const {
        return area() <= other.area();
    }

    // Операции с присваиванием
    Triangle& operator+=(const Triangle& other) {
        a += other.a;
        b += other.b;
        c += other.c;
        return *this;
    }

    Triangle& operator-=(const Triangle& other) {
        a -= other.a;
        b -= other.b;
        c -= other.c;
        return *this;
    }

    Triangle& operator*=(double scalar) {
        a *= scalar;
        b *= scalar;
        c *= scalar;
        return *this;
    }

    Triangle& operator/=(double scalar) {
        if (fabs(scalar) < 1e-10) {
            cerr << "Ошибка: деление на ноль.\n";
Triangle result = (t1 + t2) * 2 - t3 / 1.5;
    cout << "Сложное выражение (t1 + t2) * 2 - t3 / 1.5: " << result << endl;

    return 0;
}
