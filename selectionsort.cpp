#include <iostream>

class SelectionSort {
    
};

void print(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << ((i + 1) < size? ", ":"\n");
    }
}

int main() {
    const int size = 9;
    int list[size] = {65, 33, 98, 3, 2, 66, 89, 9, 5};
    
    std::cout << "Unsorted List:\n";
    print(list, size);

    std::cout << "Sorted List:\n";
    print(list, size);
}