#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

template<typename T>
class SuperVector
{
private:
    T* _data;
    size_t _size;
    size_t _capacity;
public:
    SuperVector() : _data(nullptr), _size(0), _capacity(0){std::cout<<"default constructor"<<std::endl;}

    SuperVector(std::initializer_list<T> init_list) : _size(init_list.size()), _capacity(init_list.size()) 
    {
        _data = new T[_capacity];
        size_t index = 0;

        for (auto value : init_list) 
        {
            _data[index++] = value;
        }
    }
    
    SuperVector(size_t size) : _size(size), _capacity(size)
    {
        _data = new T[_capacity]();
    }

    
    
    SuperVector(const SuperVector& other) : _size(other._size), _capacity(other._capacity)
    {
        _data = new T[_capacity];
        for (size_t i = 0; i < _size; i++)
        {
            _data[i] = other._data[i];
        }
    }

    T Get(size_t index) const
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

    ~SuperVector()
    {
        delete[] _data;
    }
    void DisplayVector()
    {
        for (int i = 0; i < _size; ++i)
        {
            std::cout<<Get(i)<< " ";
        }
        std::cout<<"\n";
    }
};

void DisplayVector_int(const SuperVector<int>& vector)
{
    for (int i = 0; i < vector.Size(); ++i)
    {
        std::cout<<vector.Get(i)<< " ";
    }
}
void DisplayVector_float(const SuperVector<float>& vector)
{
    for (int i = 0; i < vector.Size(); ++i)
    {
        std::cout<<vector.Get(i)<< " ";
    }
}
void DisplayVector_double(const SuperVector<double>& vector)
{
    for (int i = 0; i < vector.Size(); ++i)
    {
        std::cout<<vector.Get(i)<< " ";
    }
}


int main()
{
    SuperVector<int> vector={1,2,3,4};
    SuperVector<int> vector2(vector);
    SuperVector<double> vector3={1.1,2.3};
    vector.DisplayVector();
    vector2.DisplayVector();
    vector3.DisplayVector();
    return 0;       
}