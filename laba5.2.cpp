#include <iostream>

// Шаблонная функция для разделения массива
template <typename T>
void splitArray(T* array, int size, T delimiter) {
    int count = 0; // Счётчик элементов до разделителя
    
    std::cout << "Часть 1: ";
    for (int i = 0; i < size; i++) {
        if (array[i] == delimiter) {
            break; // Нашли разделитель — останавливаемся
        }
        std::cout << array[i] << " ";
        count++;
    }
    std::cout << std::endl;
    
    if (count < size) {
        std::cout << "Часть 2: ";
        for (int i = count + 1; i < size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    } else {
        std::cout << "Разделитель не найден!" << std::endl;
    }
}

int main() {
    const int size = 8;
    int arr[size] = {1, 2, 3, 0, 4, 5, 6, 7}; // 0 — разделитель
    
    int delimiter = 0;
    
    // Вызываем шаблонную функцию
    splitArray(arr, size, delimiter);
    
    return 0;
}
