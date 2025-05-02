#include <iostream>

int generate_random_number(int start, int end);
void fill_array(int* arr, unsigned int size);
void print_array(int* arr, unsigned int size);
void append(int*& arr, int& size, int value,int index);
void remove(int*& arr, int& size);
void remove_index(int*& arr, int& size,int index);

int main() {
    srand(time(NULL));

    int arr_size;
    std::cout << "Enter array size: ";
    std::cin >> arr_size;
    int* arr = new int[arr_size];
    fill_array(arr, arr_size);
    print_array(arr, arr_size);
    append(arr, arr_size, 1,3);
    print_array(arr, arr_size);
    remove(arr,arr_size);
    print_array(arr, arr_size);
    remove_index(arr,arr_size,3);
    print_array(arr, arr_size);
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

void append(int*& arr, int& size, int value,int index) {
    int* temp_arr = new int[size + 1];
    for (size_t i = 0; i < index; i++)
    {
        temp_arr[i] = arr[i];
    }
    temp_arr[index] = value;
    for (size_t i = index+1; i < size+1; i++)
    {
        temp_arr[i] = arr[i-1];
    }
    delete[] arr;
    arr = temp_arr;
    size++;
}

void remove(int*& arr, int& size) {
    int* temp_arr = new int[size - 1];
    for (size_t i = 0; i < size-1; i++)
    {
        temp_arr[i] = arr[i];
    }
    delete[] arr;
    arr = temp_arr;
    size--;
}

void remove_index(int*& arr, int& size,int index) {
    int* temp_arr = new int[size - 1];
    for (size_t i = 0; i < index; i++)
    {
        temp_arr[i] = arr[i];
    }
    for (size_t i = index; i < size-1; i++)
    {
        temp_arr[i] = arr[i+1];
    }
    delete[] arr;
    arr = temp_arr;
    size--;
}