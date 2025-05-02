#include<iostream>
int** generate_2d_matrix(int rows, int cols) {
    if (rows <= 0 || cols <= 0) return nullptr;

    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols]{};
    }

    return arr;
}

void swap(int& first_value, int& second_value) {
    int temp = first_value;
    first_value = second_value;
    second_value = temp;
}

void fill_matrix(int**& arr, int rows, int cols, int start, int end) {

    if (!arr || rows <= 0 || cols <= 0 || start == end) return;

    if (start > end) swap(start, end);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = start + rand() % (end - start);
        }
    }


}

void print_array(int** arr, int rows, int cols) {

    if (!arr || rows <= 0 || cols <= 0) return;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << "\n";
    }

}

void merge_matrix(int**& matrix1, int**& matrix2, int row1, int col1, int row2, int col2)
{
    if (row1==row2)
    {
        int cols=col1+col2;
        int** temp = generate_2d_matrix(row1, cols);
        for (int i = 0; i < row1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                temp[i][j] = matrix1[i][j];
            }
            for (int k = 0; k < col2; k++)
            {
                temp[i][col1+k] = matrix2[i][k];
            }
        }
        for (int i = 0; i < row1; i++)
        {
            delete[] matrix1[i];
        }
        delete[] matrix1;
        matrix1 = temp;
    }
    else if (row1>row2)
    {
        int cols=col1+col2;
        int** temp = generate_2d_matrix(row1, cols);
        for (int i = 0; i < row1-1; i++)
        {
            for (int j = 0; j < col1; j++)
            {
                temp[i][j] = matrix1[i][j];
            }
            for (int k = 0; k < col2; k++)
            {
                temp[i][col1+k] = matrix2[i][k];
            }
        }
        for (int i = 0; i < col1; i++)
        {
            temp[row1-1][i]=matrix1[row1-1][i];
        }
        for (int i = 0; i < col2; i++)
        {
            temp[row1-1][col1+i]=0;
        }
        for (int i = 0; i < row1; i++)
        {
            delete[] matrix1[i];
        }
        delete[] matrix1;
        matrix1 = temp;
    }
    else
    {
        int cols=col1+col2;
        int** temp = generate_2d_matrix(row2, cols);
        for (int i = 0; i < row2-1; i++)
        {
            for (int j = 0; j < col2; j++)
            {
                temp[i][j] = matrix2[i][j];
            }
            for (int k = 0; k < col1; k++)
            {
                temp[i][col2+k] = matrix1[i][k];
            }
        }
        for (int i = 0; i < col2; i++)
        {
            temp[row2-1][i]=matrix2[row2-1][i];
        }
        for (int i = 0; i < col1; i++)
        {
            temp[row2-1][col2+i]=0;
        }
        for (int i = 0; i < row2; i++)
        {
            delete[] matrix2[i];
        }
        delete[] matrix2;
        matrix2 = temp;
    }
}
int main()
{
    srand(time(0));
    int** arr=generate_2d_matrix(3,3);
    fill_matrix(arr,3,3,0,10);
    print_array(arr,3,3);
    std::cout << "\n";
    int** arr_2=generate_2d_matrix(2,2);
    fill_matrix(arr_2,2,2,0,10);
    print_array(arr_2,2,2);
    std::cout << "\n";
    merge_matrix(arr,arr_2,3,3,2,2);
    print_array(arr,3,5);
    return 0;
}
