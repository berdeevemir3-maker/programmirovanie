#include <iostream>
#include <type_traits>

// ================== C++11 версия (до Fold expressions) ==================
template<typename T>
bool allTrue(T cond) {
    return static_cast<bool>(cond);
}

template<typename First, typename... Rest>
bool allTrue(First first, Rest... rest) {
    return static_cast<bool>(first) && allTrue(rest...);
}

// ================== C++17 версия (с Fold expressions) ==================
template<typename... Conditions>
bool allTrue17(Conditions... conditions) {
    return (... && static_cast<bool>(conditions));
}

// ================== Тестирование ==================
int main() {
    std::cout << "=== C++11-style allTrue ===\n";
    std::cout << "allTrue(true, true, true) = " << allTrue(true, true, true) << "\n";
    std::cout << "allTrue(true, false, true) = " << allTrue(true, false, true) << "\n";
    std::cout << "allTrue(5 > 3, 2 == 2) = " << allTrue(5 > 3, 2 == 2) << "\n";
    
    std::cout << "\n=== C++17-style allTrue ===\n";
    std::cout << "allTrue17(true, true, true) = " << allTrue17(true, true, true) << "\n";
    std::cout << "allTrue17(true, false, true) = " << allTrue17(true, false, true) << "\n";
    std::cout << "allTrue17(5 > 3, 2 == 2) = " << allTrue17(5 > 3, 2 == 2) << "\n";

    return 0;
}
