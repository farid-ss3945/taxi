#include <iostream>

class SuperVector {
private:
    int* _data;
    size_t _size;
    size_t _capacity;

public:
    SuperVector() : _data(nullptr), _size(0), _capacity(0) {
        std::cout << "default constructor\n";
    }

    SuperVector(size_t size) : _size(size), _capacity(size) {
        _data = new int[_capacity]();
    }

    SuperVector(const SuperVector& other) : _size(other._size), _capacity(other._capacity) {
        _data = new int[_capacity];
        for (size_t i = 0; i < _size; i++) {
            _data[i] = other._data[i];
        }
    }

    int Get(size_t index) const {
        if (index < _size && index >= 0) {
            return _data[index];
        }
        return 0;
    }

    size_t Size() const {
        return _size;
    }

    void Set(int index, int value) {
        if (index < _size && index >= 0) {
            _data[index] = value;
        }
    }

    void resizeArray(int*& data, int& size) {
        int newsize = size + 1;
        int* dataTemp = new int[newsize];
        for (int i = 0; i < size; i++) {
            dataTemp[i] = _data[i];
        }
        delete[] _data;
        _data = dataTemp;
        size = newsize;
    }

    SuperVector& operator+=(const SuperVector& other) {
        size_t minSize;
        if (_size < other._size) {
            minSize = _size;
        } else {
            minSize = other._size;
        }

        for (size_t i = 0; i < minSize; ++i) {
            _data[i] += other._data[i];
        }

        return *this;
    }

    SuperVector& operator-=(const SuperVector& other) {
        size_t minSize;
        if (_size < other._size) {
            minSize = _size;
        } else {
            minSize = other._size;
        }

        for (size_t i = 0; i < minSize; ++i) {
            _data[i] -= other._data[i];
        }

        return *this;
    }

    SuperVector& operator*=(const SuperVector& other) {
        size_t minSize;
        if (_size < other._size) {
            minSize = _size;
        } else {
            minSize = other._size;
        }

        for (size_t i = 0; i < minSize; ++i) {
            _data[i] *= other._data[i];
        }

        return *this;
    }

    SuperVector& operator/=(const SuperVector& other) {
        size_t minSize;
        if (_size < other._size) {
            minSize = _size;
        } else {
            minSize = other._size;
        }

        for (size_t i = 0; i < minSize; ++i) {
            if (other._data[i] != 0) {
                _data[i] /= other._data[i];
            } else {
                std::cout << "Division by zero at index " << i << std::endl;
            }
        }

        return *this;
    }

    SuperVector& operator+=(int scalar) {
        for (size_t i = 0; i < _size; ++i) {
            _data[i] += scalar;
        }
        return *this;
    }

    SuperVector& operator-=(int scalar) {
        for (size_t i = 0; i < _size; ++i) {
            _data[i] -= scalar;
        }
        return *this;
    }

    SuperVector& operator*=(int scalar) {
        for (size_t i = 0; i < _size; ++i) {
            _data[i] *= scalar;
        }
        return *this;
    }

    SuperVector& operator/=(int scalar) {
        if (scalar == 0) {
            std::cout << "Division by zero\n";
            return *this;
        }
        for (size_t i = 0; i < _size; ++i) {
            _data[i] /= scalar;
        }
        return *this;
    }

    SuperVector& operator++() {
        for (size_t i = 0; i < _size; ++i) {
            ++_data[i];
        }
        return *this;
    }

    SuperVector operator++(int) {
        SuperVector temp = *this;
        for (size_t i = 0; i < _size; ++i) {
            _data[i]++;
        }
        return temp;
    }

    SuperVector& operator--() {
        for (size_t i = 0; i < _size; ++i) {
            --_data[i];
        }
        return *this;
    }

    SuperVector operator--(int) {
        SuperVector temp = *this;
        for (size_t i = 0; i < _size; ++i) {
            _data[i]--;
        }
        return temp;
    }

    ~SuperVector() {
        delete[] _data;
    }

    friend std::ostream& operator<<(std::ostream& os, const SuperVector& vec) {
        for (size_t i = 0; i < vec._size; ++i) {
            os << vec._data[i] << " ";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, SuperVector& vec) {
        for (size_t i = 0; i < vec._size; ++i) {
            is >> vec._data[i];
        }
        return is;
    }
};

int main() {
    SuperVector vector1(5);
    SuperVector vector2(5);

    for (size_t i = 0; i < vector1.Size(); ++i) {
        vector1.Set(i, i + 1);
        vector2.Set(i, (i + 1) * 2);
    }

    std::cout<< vector1 << "\n";
    std::cout<< vector2 << "\n";

    vector1 += vector2;
    std::cout << vector1 << "\n";

    vector1 -= vector2;
    std::cout<< vector1 << "\n";

    vector1 *= vector2;
    std::cout<< vector1 << "\n";

    vector1 /= vector2;
    std::cout << vector1 << "\n";

    vector1++;
    std::cout << vector1 << "\n";

    ++vector1;
    std::cout<< vector1 << "\n";

    vector1--;
    std::cout << vector1 << "\n";

    --vector1;
    std::cout << vector1 << "\n";

    return 0;
}
