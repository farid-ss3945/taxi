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

    SuperVector operator+(const SuperVector& rhs)
    {
        if (_size >= rhs._size)
        {
            SuperVector newVector(Size());
            for (size_t i = 0; i < rhs._size; i++)
            {
                int k=Get(i)+rhs.Get(i);
                newVector.Set(i,k);
            }
            return newVector;
        }
        else if (_size <= rhs._size)
        {
            SuperVector newVector(rhs.Size());
            for (size_t i = 0; i < _size; i++)
            {
                int k=Get(i)+rhs.Get(i);
                newVector.Set(i,k);
            }
            return newVector;
        }
        
    }
    
    SuperVector operator-(const SuperVector& rhs)
    {
        if (_size >= rhs._size)
        {
            SuperVector newVector(Size());
            for (size_t i = 0; i < rhs._size; i++)
            {
                int k=Get(i)-rhs.Get(i);
                newVector.Set(i,k);
            }
            return newVector;
        }
        else if (_size <= rhs._size)
        {
            SuperVector newVector(rhs.Size());
            for (size_t i = 0; i < _size; i++)
            {
                int k=Get(i)-rhs.Get(i);
                newVector.Set(i,k);
            }
            return newVector;
        }
        
    }
    SuperVector operator*(const SuperVector& rhs)
    {
        if (_size >= rhs._size)
        {
            SuperVector newVector(Size());
            for (size_t i = 0; i < rhs._size; i++)
            {
                int k=Get(i)*rhs.Get(i);
                newVector.Set(i,k);
            }
            return newVector;
        }
        else if (_size <= rhs._size)
        {
            SuperVector newVector(rhs.Size());
            for (size_t i = 0; i < _size; i++)
            {
                int k=Get(i)*rhs.Get(i);
                newVector.Set(i,k);
            }
            return newVector;
        }
        
    }
    SuperVector operator/(const SuperVector& rhs)
    {
        
        if (_size >= rhs._size)
        {
            SuperVector newVector(Size());
            for (size_t i = 0; i < rhs._size; i++)
            {
                if (rhs.Get(i)==0)
                {
                    newVector.Set(i,0);
                }
                else
                {
                    int k=Get(i)/rhs.Get(i);
                    newVector.Set(i,k);
                }
            }
            return newVector;
        }
        else if (_size <= rhs._size)
        {
            SuperVector newVector(rhs.Size());
            for (size_t i = 0; i < _size; i++)
            {
                if (rhs.Get(i)==0)
                {
                    newVector.Set(i,0);
                }
                else
                {
                    int k=Get(i)/rhs.Get(i);
                    newVector.Set(i,k);
                }
            }
            return newVector;
        }
        
    }
    int& operator[](size_t index) {
        return _data[index];
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
    vector.Set(0, 10);
    SuperVector vector2(4);
    SuperVector vector3=vector+vector2;
    SuperVector vector4(4);
    vector4.Set(0, 11);
    SuperVector vector5(10);
    SuperVector vector6=vector5-vector4;
    DisplayVector(vector3);
    DisplayVector(vector6);
    SuperVector vector7=vector3*vector6;
    DisplayVector(vector7);
    SuperVector vector8=vector7/vector6;
    DisplayVector(vector8);
    std::cout<<vector8[0];
    
    return 0;       
}