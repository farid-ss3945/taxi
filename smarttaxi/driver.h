#pragma once
#include "User.h"
#include "Car.h"
#include <fstream>
#include <iostream>

class Driver : public User
{
protected:
    int _license;
    float _rating;
    std::string _class;
    Car _myCar;
public:
    Driver() : User()
    {
        
    }
    
    Driver& operator=(const Driver& other)
    {
        if (this != &other)
        {
            User::operator=(other);

            _license = other._license;
            _rating = other._rating;
            _myCar = other._myCar;
        }
        return *this;
    }

    
    Driver(const Driver& other): _license(other._license), _myCar(other._myCar), _rating(other._rating)
    {
        
    }
    void SetLicense(int license)
    {
        _license = license;
    }

    void SetRating(float rating)
    {
        _rating = rating;
    }
    
    void SetClass(std::string ex_class)
    {
        _class=ex_class;
    }

    std::string GetClass()
    {
        return _class;
    }
    
    int GetLicense()
    {
        return _license;
    }
    void SetmyCar(std::string brand,std::string model,int year)
    {
        _myCar.SetBrand(brand);
        _myCar.SetModel(model);
        _myCar.SetYear(year);   
    }

    void writeToFile(std::ofstream& out)  {
        size_t len_name = _name.size();
        out.write(reinterpret_cast<const char*>(&len_name), sizeof(len_name));
        out.write(&_name[0], len_name);
        size_t len_surname = _surname.size();
        out.write(reinterpret_cast<const char*>(&len_surname), sizeof(len_surname));
        out.write(&_surname[0], len_surname);
        out.write(reinterpret_cast<const char*>(&_age), sizeof(_age));
        out.write(reinterpret_cast<const char*>(&_rating), sizeof(_rating));
        size_t len_class = _class.size();
        out.write(reinterpret_cast<const char*>(&len_class), sizeof(len_class));
        out.write(&_class[0], len_class);
        size_t len_mail = _mail.size();
        out.write(reinterpret_cast<const char*>(&len_mail), sizeof(len_mail));
        out.write(&_mail[0], len_mail);
        size_t len_password = _password.size();
        out.write(reinterpret_cast<const char*>(&len_password), sizeof(len_password));
        out.write(&_password[0], len_password);

        _myCar.car_to_file(out); 
    }

    void readFromFile(std::ifstream& in) {
        size_t len_name;
        in.read(reinterpret_cast<char*>(&len_name), sizeof(len_name));
        _name.resize(len_name);
        in.read(&_name[0], len_name);

        size_t len_surname;
        in.read(reinterpret_cast<char*>(&len_surname), sizeof(len_surname));
        _surname.resize(len_surname);
        in.read(&_surname[0], len_surname);

        in.read(reinterpret_cast<char*>(&_age), sizeof(_age));
        in.read(reinterpret_cast<char*>(&_rating), sizeof(_rating));

        size_t len_class;
        in.read(reinterpret_cast<char*>(&len_class), sizeof(len_class));
        _class.resize(len_class);
        in.read(&_class[0], len_class);

        size_t len_mail;
        in.read(reinterpret_cast<char*>(&len_mail), sizeof(len_mail));
        _mail.resize(len_mail);
        in.read(&_mail[0], len_mail);

        size_t len_password;
        in.read(reinterpret_cast<char*>(&len_password), sizeof(len_password));
        _password.resize(len_password);
        in.read(&_password[0], len_password);

        _myCar.car_from_file(in); 
    }

    bool checknget(std::ifstream& in)
    {
        Driver temp;
        while (in)
        {
            temp.readFromFile(in);
            if (temp._mail==_mail && temp._password==_password)
            {
                *this=temp;
                return true;
            }
        }
        return false;
    }

    void print()  {
        std::cout << "Name: " << _name << "\n";
        std::cout << "Surname: " << _surname << "\n";
        std::cout << "Age: " << _age << "\n";
        std::cout << "Rating: " << _rating << "\n";
        std::cout << "Class: " << _class << "\n";
        std::cout << "Email: " << _mail << "\n";
        std::cout << "Password: " << _password << "\n";
        _myCar.print();
    }
    
};