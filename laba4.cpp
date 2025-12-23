double discriminant = b * b - 4 * a * c;
    
    if (discriminant < 0) {
        throw MyQuadException(a, b, c, "Дискриминант отрицательный!");
    }
    
    double x1 = (-b + sqrt(discriminant)) / (2 * a);
    double x2 = (-b - sqrt(discriminant)) / (2 * a);
    
    cout << "Корни уравнения: x1 = " << x1 << ", x2 = " << x2 << endl;
}

// ------------------------------------------------------------
// Главная функция с обработкой исключений
int main() {
    double a, b, c;
    
    cout << "Введите коэффициенты квадратного уравнения (a, b, c): ";
    cin >> a >> b >> c;
    
    // Демонстрация всех вариантов обработки исключений
    cout << "\n=== Вариант 1: Без спецификации исключений ===" << endl;
    try {
        solveQuadratic1(a, b, c);
    } catch (const char* msg) {
        cout << "Ошибка: " << msg << endl;
    }
    
    cout << "\n=== Вариант 2: Со спецификацией throw() ===" << endl;
    try {
        solveQuadratic2(a, b, c);
    } catch (const char* msg) {
        cout << "Ошибка: " << msg << endl;
    }
    
    cout << "\n=== Вариант 3: Со стандартным исключением ===" << endl;
    try {
        solveQuadratic3(a, b, c);
    } catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    cout << "\n=== Вариант 4: С пустым классом исключения ===" << endl;
    try {
        solveQuadratic4_empty(a, b, c);
    } catch (const EmptyException&) {
        cout << "Ошибка: Неверные параметры уравнения!" << endl;
    }
    
    cout << "\n=== Вариант 5: С классом исключения с полями ===" << endl;
    try {
        solveQuadratic5_fields(a, b, c);
    } catch (const QuadEquationException& e) {
        cout << "Ошибка для уравнения " << e.getA() << "x^2 + " 
             << e.getB() << "x + " << e.getC() << " = 0: " 
             << e.getMessage() << endl;
    }
    
    cout << "\n=== Вариант 6: С классом-наследником стандартного ===" << endl;
    try {
        solveQuadratic6_inherited(a, b, c);
    } catch (const MyQuadException& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
    
    return 0;
}
