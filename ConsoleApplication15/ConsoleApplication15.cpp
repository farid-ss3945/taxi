#include <iostream>

class Fraction {
public:
    int _numerator;
    int _denominator;

    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void Simplify() {
        int gcd_value = gcd(_numerator, _denominator);
        _numerator /= gcd_value;
        _denominator /= gcd_value;

        if (_denominator < 0) {
            _numerator = -_numerator;
            _denominator = -_denominator;
        }
    }

    Fraction(int numerator, int denominator) {
        if (denominator == 0) {
            std::cerr << "Ошибка: знаменатель не может быть равен нулю!" << std::endl;
            _numerator = 0;
            _denominator = 1;
        } else {
            _numerator = numerator;
            _denominator = denominator;
            Simplify();
        }
    }

    Fraction() : _numerator(0), _denominator(1) {}

    Fraction(const Fraction& other) : _numerator(other._numerator), _denominator(other._denominator) {}

    friend Fraction operator+(const Fraction& first, const Fraction& second) {
        int num = first._numerator * second._denominator + second._numerator * first._denominator;
        int denom = first._denominator * second._denominator;
        return Fraction(num, denom);
    }

    Fraction operator-(const Fraction& other) const {
        int num = _numerator * other._denominator - _denominator * other._numerator;
        int denom = _denominator * other._denominator;
        return Fraction(num, denom);
    }

    friend Fraction operator*(const Fraction& first, const Fraction& second) {
        Fraction result;
        result._numerator = first._numerator * second._numerator;
        result._denominator = first._denominator * second._denominator;
        result.Simplify();
        return result;
    }

    Fraction operator/(const Fraction& other) {
        if (other._numerator == 0) {
            std::cout << "Ошибка: деление на ноль!" << std::endl;
            return Fraction();
        }
        int num = _numerator * other._denominator;
        int denom = _denominator * other._numerator;
        return Fraction(num, denom);
    }

    bool operator==(const Fraction& other) const {
        return _numerator == other._numerator && _denominator == other._denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return _numerator * other._denominator < _denominator * other._numerator;
    }

    bool operator>(const Fraction& other) const {
        return other < *this;
    }

    bool operator<=(const Fraction& other) const {
        return !(other < *this);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& obj) {
        os << obj._numerator << "/" << obj._denominator;
        return os;
    }
};

int main() {
    Fraction a(3, 4);
    Fraction b(2, 5);
    Fraction c = a + b;
    
    std::cout <<a<<" "<<c <<std::endl;

    return 0;
}
