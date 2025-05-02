#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Car
{
private:
    char _brand[20];
    char _model[20];
    int _year;
    int _mileage;
public:
    Car(const char* brand,const char* model, int year, int mileage)
    {
        strcpy(_brand,brand);
        strcpy(_model,model);
        _year = year;
        _mileage = mileage;
    };
    Car()
    {
        strcpy(_brand,"buggati");
        strcpy(_model,"chiron");
        _year = 2016;
        _mileage = 4;
    }
    void setMileage(int mileage)
    {
        if (mileage >= _mileage)
        {
            _mileage = mileage;
        }
        
    }
    int getMileage()
    {
        return _mileage;
    }
    int getAge(int currentYear)
    {
        return 2025-_year;
    }
    void drive(int km)
    {
        _mileage += km;
    }
};

int main()
{
    Car car("BMW", "X5", 1999,12);
    car.setMileage(14);
    car.drive(10);
    std::cout <<car.getMileage()<<std::endl<<car.getAge(2025)<<std::endl;

    return 0;
    
}
