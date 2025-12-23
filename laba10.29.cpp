#include <iostream>
#include <cmath>

// Простейший метод прямоугольников (левые)
template<typename Func, typename... Points>
auto integrate(Func&& func, Points... points) {
    // Собираем точки в массив (в реальном коде лучше использовать std::array)
    double arr[] = {static_cast<double>(points)...};
    size_t n = sizeof...(points);
    
    if (n < 2) return 0.0;
    
    double sum = 0.0;
    for (size_t i = 0; i < n - 1; ++i) {
        double dx = arr[i + 1] - arr[i];
        sum += func(arr[i]) * dx;
    }
    
    return sum;
}

// Тестирование
int main() {
    // Интеграл x^2 от 0 до 1 ≈ 1/3
    auto f1 = [](double x) { return x * x; };
    double result1 = integrate(f1, 0.0, 0.5, 1.0);
    std::cout << "∫x^2 dx from 0 to 1 (approx) = " << result1 << "\n";
    
    // Интеграл sin(x) от 0 до π ≈ 2
    auto f2 = [](double x) { return std::sin(x); };
    double result2 = integrate(f2, 0.0, 1.0, 2.0, 3.14159);
    std::cout << "∫sin(x) dx from 0 to π (approx) = " << result2 << "\n";
    
    // Интеграл константы
    auto f3 = [](double x) { return 2.0; };
    double result3 = integrate(f3, 0.0, 5.0);
    std::cout << "∫2 dx from 0 to 5 = " << result3 << "\n";

    return 0;
}
