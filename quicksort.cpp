#include <iostream>

class QuickSort {
    public:
        void sort(int *array, size_t size) {
            quickSort(array, size);
        }

    private:
        int partition(int *array, size_t size) {
            //if the size is more than 2, implement median-of-three for pivot
            if (size > 2) {
                int mid = size / 2;
                if (array[mid] < array[0]) {
                    swap(array[mid], array[0]);
                }

                if (array[size - 1] < array[0]) {
                    swap(array[size - 1], array[0]);
                }

                if (array[size - 1] < array[mid]) {
                    swap(array[size - 1], array[mid]);
                }

                swap(array[mid], array[size - 1]); //with the median is sorted, then swap the middle with high, so that the pivot is picked the middle
            }

            int *pivot = &array[size - 1]; //pick the lass element as pivot
            size_t low = 0; 

            for (size_t i = 0; i < size - 1; i ++) {
                if (array[i] < *pivot) {
                    if (i != low) //prevent swaping the same variable
                        swap(array[i], array[low]);
                    low++; //count the element that are less(or more in reverse) than the pivot
                }
            }

            swap(array[low], *pivot); //move the pivot into between the lower and higher value elements compare to it

            return low; //return the last pivot index
        }

        void quickSort(int *array, size_t size) {
            if (size <= 1) return; //break the recursion if the size is less than two

            size_t pivot_index = partition(array, size); //get the pivot last index
            size_t right_partition_size = size - pivot_index - 1; //calculate the size of the last partition after the pivot index

            quickSort(array, pivot_index); //make a new recursion as the size is upto pivot_index
            quickSort(array + pivot_index + 1, right_partition_size); //make a new recursion after the pivot index
        }

        void swap(int &a, int &b) {
            int temp = a;
            a = b;
            b = temp;
        }
};

void print(int *array, size_t size) {
    for (size_t i = 0; i < size; i++) {
        std::cout << array[i] << ((i + 1) < size? ", ":"\n");
    }
}

int main() {
    const size_t size = 9;
    int list[size] = {65, 33, 98, 7, 28, 66, 89, 9, 22};
    
    std::cout << "Unsorted List:\n";
    print(list, size);

    QuickSort quickSort;
    quickSort.sort(list, size);

    std::cout << "Sorted List:\n";
    print(list, size);
}