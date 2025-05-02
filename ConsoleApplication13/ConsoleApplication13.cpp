#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



class SuperVector
{
private:
    int* _data;
    size_t _size;
    size_t _capacity;
public:
    SuperVector() : _data(nullptr), _size(0), _capacity(0){std::cout<<"default constructor"<<"\n";}
    SuperVector(size_t size) : _size(size), _capacity(size)
    {
        _data = new int[_capacity]();
    }

    
    SuperVector(const SuperVector& other) : _size(other._size), _capacity(other._capacity)
    {
        _data = new int[_capacity];
        for (size_t i = 0; i < _size; i++)
        {
            _data[i] = other._data[i];
        }
    }

    int Get(size_t index) const
    {
        if (index <= _size && index >= 0)
        {
            return _data[index];
        }
        return 0;
    }

    size_t Size() const
    {
        return _size;
    }

    void Set(int index, int value)
    {
        if (index <= _size && index >= 0)
        {
            _data[index] = value;
        }
    }
    

    void PushBack(int value,int size) 
    {
        resizeArray(_data,size);
        _size = size;
        _data[size-1] = value;
        
    }

    void Insert(int index, int value, int size) 
    {
        resizeArray(_data, size);
        _size = size;
        for (int j = size - 1; j > index; j--) 
        {
            _data[j] = _data[j - 1];
        }
        _data[index] = value;
    }


    void remove(int size) {
        int* temp_arr = new int[size - 1];
        for (size_t i = 0; i < size-1; i++)
        {
            temp_arr[i] = _data[i];
        }
        delete[] _data;
        _data = temp_arr;
        size--;
        _size=size;
    }

    void remove_index(int index,int size) {
        int* temp_arr = new int[size - 1];
        for (size_t i = 0; i < size-1; i++)
        {
            temp_arr[i] = _data[i];
        }
        for (size_t i = index; i < size-1; i++)
        {
            temp_arr[i] = _data[i+1];
        }
        delete[] _data;
        _data = temp_arr;
        size--;
        _size=size;
    }

    void resizeArray(int*& data,int& size)
    {
        int newsize = size + 1;
        int* dataTemp = new int[newsize];
        for (int i = 0; i < size; i++)
        {
            dataTemp[i] = _data[i];
        }
        delete[] _data;
        _data = dataTemp;
        size = newsize;
    }

    ~SuperVector()
    {
        delete[] _data;
    }
    
};

void DisplayVector(const SuperVector& vector)
{
    for (int i = 0; i < vector.Size(); i++)
    {
        std::cout<<vector.Get(i)<< " ";
        
    }
    std::cout<<"\n";
}


int main()
{
    SuperVector vector(10);
    SuperVector vector2(vector);
    DisplayVector(vector2);
    vector2.Set(0, 10);
    DisplayVector(vector2);
    vector2.PushBack(3, 10);
    DisplayVector(vector2);
    vector2.Insert(5, 1, 11);
    DisplayVector(vector2);
    vector2.remove(12);
    DisplayVector(vector2);
    vector2.remove_index(5, 11);
    DisplayVector(vector2);
    return 0;       
}