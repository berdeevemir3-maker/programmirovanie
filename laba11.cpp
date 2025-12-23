#include <iostream>
#include <concepts>

// Концепт для целочисленных типов
template<typename T>
concept Integral = std::integral<T>;

// Constexpr лямбда для вычисления биномиального коэффициента C(n, k)
template<Integral T>
constexpr auto binomialCoefficient = [](T n, T k) constexpr {
    if (k < 0 || k > n) return static_cast<T>(0);
    if (k == 0 || k == n) return static_cast<T>(1);
    
    // Оптимизация: используем меньший k
    if (k > n - k) k = n - k;
    
    T result = 1;
    for (T i = 1; i <= k; ++i) {
        result = result * (n - k + i) / i;
    }
    return result;
};

int main() {
    // Тестирование во время компиляции
    constexpr auto bc1 = binomialCoefficient<int>(5, 2);    // C(5,2) = 10
    constexpr auto bc2 = binomialCoefficient<int>(7, 3);    // C(7,3) = 35
    constexpr auto bc3 = binomialCoefficient<int>(4, 4);    // C(4,4) = 1
    constexpr auto bc4 = binomialCoefficient<int>(10, 11);  // C(10,11) = 0
    
    // Проверка
    static_assert(bc1 == 10, "C(5,2) должно быть 10");
    static_assert(bc2 == 35, "C(7,3) должно быть 35");
    static_assert(bc3 == 1, "C(4,4) должно быть 1");
    static_assert(bc4 == 0, "C(10,11) должно быть 0");
    
    // Вывод результатов
    std::cout << "Биномиальные коэффициенты (вычисленные на этапе компиляции):\n";
    std::cout << "C(5, 2) = " << bc1 << "\n";
    std::cout << "C(7, 3) = " << bc2 << "\n";
    std::cout << "C(4, 4) = " << bc3 << "\n";
    std::cout << "C(10, 11) = " << bc4 << "\n";
    
    // Тестирование во время выполнения
    std::cout << "\nВведите n и k для вычисления C(n,k): ";
    int n, k;
    std::cin >> n >> k;
    
    auto result = binomialCoefficient<int>(n, k);
    std::cout << "C(" << n << ", " << k << ") = " << result << "\n";
    
    // Проверка треугольника Паскаля
    std::cout << "\nПервые 6 строк треугольника Паскаля:\n";
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j <= i; ++j) {
            std::cout << binomialCoefficient<int>(i, j) << " ";
        }
        std::cout << "\n";
    }
    
    return 0;
}
