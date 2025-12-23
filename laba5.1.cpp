#include <iostream>

// Шаблонная функция для вырезки подмассива
template <typename T>
T* extractSubarray(T* array, int size, int startIndex, int subLength) {
    if (startIndex < 0  subLength <= 0  startIndex + subLength > size) {
        return nullptr; // Некорректные параметры
    }
    
    T* subarray = new T[subLength]; // Выделяем память для подмассива
    
    for (int i = 0; i < subLength; i++) {
        subarray[i] = array[startIndex + i]; // Копируем элементы
    }
    
    return subarray; // Возвращаем новый массив
}

int main() {
    const int size = 8;
    int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8};
    
    int startIndex = 2;
    int subLength = 4;
    
    // Вызываем шаблонную функцию
    int* subarr = extractSubarray(arr, size, startIndex, subLength);
    
    if (subarr != nullptr) {
        std::cout << "Подмассив: ";
        for (int i = 0; i < subLength; i++) {
            std::cout << subarr[i] << " ";
        }
        std::cout << std::endl;
        
        delete[] subarr; // Освобождаем память
    } else {
        std::cout << "Ошибка в параметрах!" << std::endl;
    }
    
    return 0;
}
