#include <iostream>

int generate_random_number(int start, int end);
void fill_array(int* arr, unsigned int size);
void print_array(int* arr, unsigned int size);

template <typename T>
bool ascending(T a, T b) {
    return a < b; 
}

template <typename T>
bool descending(T a, T b) {
    return a > b; 
}

template <typename T>
bool evenFirst(T a, T b) {
    if (a % 2 == 0 && b % 2 != 0) return true;  
    if (a % 2 != 0 && b % 2 == 0) return false; 
    return a < b; 
}

template <typename T>
bool oddFirst(T a, T b) {
    if (a % 2 != 0 && b % 2 == 0) return true;  
    if (a % 2 == 0 && b % 2 != 0) return false; 
    return a < b; 
}

template <typename T>
void sort_array(T arr[], int size, bool(*comparator)(T, T)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (!comparator(arr[j], arr[j + 1])) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}



int main() {
    srand(time(NULL));
    int arr[10] ;
    fill_array(arr, 10);
    print_array(arr, 10);
    sort_array(arr, 10, ascending);
    print_array(arr, 10);
    sort_array(arr, 10, descending);
    print_array(arr, 10);
    sort_array(arr, 10, evenFirst);
    print_array(arr, 10);
    sort_array(arr, 10, oddFirst);
    print_array(arr, 10);

}

int generate_random_number(int start, int end) {
	
    return (rand() % (end - start) + start);
}

void fill_array(int* arr, unsigned int size) {
    for (size_t i = 0; i < size; i++)
    {
        arr[i] = generate_random_number(-50, 50);
    }
}

void print_array(int* arr, unsigned int size) {
    for (size_t i = 0; i < size; i++)
    {
        std::cout << "[" << arr[i] << "]";
    }std::cout << '\n';
}