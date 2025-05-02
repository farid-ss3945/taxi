#pragma once
#include <string>
#include <fstream>
#include <iostream>

class Car
{
private:
    std::string _brand,_model;
    int _year;
public:
    Car()
    {
        
    }
    Car& operator=(const Car& other)
    {
        if (this != &other)
        {
            _brand = other._brand;
            _model = other._model;
            _year = other._year;
        }
        return *this;
    }

    void SetBrand(std::string brand)
    {
        _brand=brand;
    }
    void SetModel(std::string model)
    {
        _model=model;
    }
    void SetYear(int year)
    {
        _year = year;
    }

    void car_to_file(std::ofstream& out)
    {
        size_t len_brand=_brand.size();
        size_t len_model=_model.size();
        out.write(reinterpret_cast<const char*>(&len_brand),sizeof(size_t));
        out.write(reinterpret_cast<const char*>(&len_model),sizeof(size_t));
        out.write(&_brand[0], len_brand);
        out.write(&_model[0], len_model);
        out.write(reinterpret_cast<const char*>(&_year),sizeof(_year));
    }

    void car_from_file(std::ifstream& in) {
        size_t len_brand, len_model;
        in.read(reinterpret_cast<char*>(&len_brand), sizeof(len_brand));
        in.read(reinterpret_cast<char*>(&len_model), sizeof(len_model));

        _brand.resize(len_brand);
        _model.resize(len_model);

        in.read(&_brand[0], len_brand);
        in.read(&_model[0], len_model);

        in.read(reinterpret_cast<char*>(&_year), sizeof(_year));
    }

    void print() {
        std::cout << "Car Brand: " << _brand << "\n";
        std::cout << "Car Model: " << _model << "\n";
        std::cout << "Car Year: " << _year << "\n";
    }
};