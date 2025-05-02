#include<iostream>

class Fraction
{
    public:
    int _numerator,_denominator;
    Fraction(int numerator, int denominator)
    {
        if(denominator != 0)
        {
            _numerator = numerator / denominator;
        }
        if (numerator % denominator == 0)
        {
            
        }
    }
    int operator+(int numerator,int denominator);
    // Fraction()
    // {
    //     _numerator = _numerator/_denominator;
    // }
};

int main()
{
    Fraction a(3, 4);
    Fraction b(2, 5);
    Fraction c(2,2);  // (3/4) + (2/5) = 23/20
    c._numerator = a._numerator + b._numerator;
    std::cout << c._numerator << std::endl;

    
    
    return 0;
}
