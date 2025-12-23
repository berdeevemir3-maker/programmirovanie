#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// ------------------ Реализация через структуру и внешние функции ------------------
struct TriangleStruct {
    double a, b, c; // стороны
    double A, B, C; // углы в градусах
};

void initStruct(TriangleStruct& t, double a, double b, double c) {
    if (a <= 0  b <= 0  c <= 0  a + b <= c  a + c <= b || b + c <= a) {
        cout << "Ошибка: недопустимые стороны треугольника." << endl;
        exit(1);
    }
    t.a = a; t.b = b; t.c = c;
    // Углы вычисляем по теореме косинусов
    t.A = acos((b*b + c*c - a*a) / (2*b*c)) * 180 / M_PI;
    t.B = acos((a*a + c*c - b*b) / (2*a*c)) * 180 / M_PI;
    t.C = 180 - t.A - t.B;
}

void displayStruct(const TriangleStruct& t) {
    cout << "Стороны: " << t.a << ", " << t.b << ", " << t.c << endl;
    cout << "Углы: " << t.A << ", " << t.B << ", " << t.C << " градусов" << endl;
}

double perimeterStruct(const TriangleStruct& t) {
    return t.a + t.b + t.c;
}

double areaStruct(const TriangleStruct& t) {
    double p = perimeterStruct(t) / 2;
    return sqrt(p * (p - t.a) * (p - t.b) * (p - t.c));
}

string typeStruct(const TriangleStruct& t) {
    if (t.a == t.b && t.b == t.c) return "Равносторонний";
    if (t.a == t.b  t.b == t.c  t.a == t.c) return "Равнобедренный";
    if (fabs(t.A - 90) < 1e-6  fabs(t.B - 90) < 1e-6  fabs(t.C - 90) < 1e-6)
        return "Прямоугольный";
    return "Разносторонний";
}

// ------------------ Реализация через класс ------------------
class TriangleClass {
private:
    double a, b, c;
    double A, B, C;

    void computeAngles() {
        A = acos((b*b + c*c - a*a) / (2*b*c)) * 180 / M_PI;
        B = acos((a*a + c*c - b*b) / (2*a*c)) * 180 / M_PI;
        C = 180 - A - B;
    }

public:
    void init(double side1, double side2, double side3) {
        if (side1 <= 0  side2 <= 0  side3 <= 0 ||
            side1 + side2 <= side3  side1 + side3 <= side2  side2 + side3 <= side1) {
            cout << "Ошибка: недопустимые стороны." << endl;
            exit(1);
        }
        a = side1; b = side2; c = side3;
        computeAngles();
    }

    void read() {
        cout << "Введите три стороны треугольника: ";
        cin >> a >> b >> c;
        if (a <= 0  b <= 0  c <= 0  a + b <= c  a + c <= b || b + c <= a) {
            cout << "Ошибка: недопустимые стороны." << endl;
            exit(1);
        }
        computeAngles();
    }

    void display() const {
        cout << "Стороны: " << a << ", " << b << ", " << c << endl;
        cout << "Углы: " << A << ", " << B << ", " << C << " градусов" << endl;
    }

    string toString() const {
        return "Треугольник со сторонами " + to_string(a) + ", " + to_string(b) + ", " + to_string(c);
    }

    double perimeter() const {
        return a + b + c;
    }

    double area() const {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    string type() const {
        if (a == b && b == c) return "Равносторонний";
        if (a == b  b == c  a == c) return "Равнобедренный";
        if (fabs(A - 90) < 1e-6  fabs(B - 90) < 1e-6  fabs(C - 90) < 1e-6)
            return "Прямоугольный";
        return "Разносторонний";
    }

    double height(char side) const {
        double ar = area();
        if (side == 'a') return 2 * ar / a;
        if (side == 'b') return 2 * ar / b;
        if (side == 'c') return 2 * ar / c;
        return 0;
    }
};

int main() {
    cout << "=== Реализация через структуру ===" << endl;
    TriangleStruct ts;
    initStruct(ts, 3, 4, 5);
    displayStruct(ts);
    cout << "Периметр: " << perimeterStruct(ts) << endl;
    cout << "Площадь: " << areaStruct(ts) << endl;
    cout << "Тип: " << typeStruct(ts) << endl;

    cout << "\n=== Реализация через класс ===" << endl;
    TriangleClass tc;
    tc.init(5, 5, 5);
    tc.display();
    cout << "Периметр: " << tc.perimeter() << endl;
    cout << "Площадь: " << tc.area() << endl;
    cout << "Тип: " << tc.type() << endl;
    cout << "Высота к стороне a: " << tc.height('a') << endl;
// Тестирование ввода с клавиатуры
    TriangleClass tc2;
    tc2.read();
    tc2.display();
    cout << "Площадь: " << tc2.area() << endl;
    cout << "Тип: " << tc2.type() << endl;

    return 0;
}
