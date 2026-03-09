#include <iostream>

class MergeSort {
    public:
        void mergeSort(int *array, int size) {
            if (size <= 1) return;

            int middle = size / 2;
            int remain = size - (size * 2); //a remaining element if the size is odd

            if (size > 2) {
                mergeSort(array, middle); //left recursion
                mergeSort(array + middle, middle + remain); //right recurtion
                merge(array, size, middle);
            }
        }
    private:
        void merge(int *array, int size, int middle) {

        }

};

int main() {
    
}