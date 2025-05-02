#pragma once
#include "User.h"

class Passenger : public User
{
public:
    Passenger(): User()
    {
        
    }
    Passenger& operator=(const Passenger& other)
    {
        if (this != &other)
        {
            User::operator=(other);  
        }
        return *this;
    }

    
    
    void writeToFile(std::ofstream& out)  {
        if (!out)
        {
            
        }
        size_t len_name = _name.size();
        out.write(reinterpret_cast<const char*>(&len_name), sizeof(len_name));
        out.write(&_name[0], len_name);
        size_t len_surname = _surname.size();
        out.write(reinterpret_cast<const char*>(&len_surname), sizeof(len_surname));
        out.write(&_surname[0], len_surname);
        out.write(reinterpret_cast<const char*>(&_age), sizeof(_age));
        size_t len_mail = _mail.size();
        out.write(reinterpret_cast<const char*>(&len_mail), sizeof(len_mail));
        out.write(&_mail[0], len_mail);
        size_t len_password = _password.size();
        out.write(reinterpret_cast<const char*>(&len_password), sizeof(len_password));
        out.write(&_password[0], len_password);
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

        size_t len_mail;
        in.read(reinterpret_cast<char*>(&len_mail), sizeof(len_mail));
        _mail.resize(len_mail);
        in.read(&_mail[0], len_mail);

        size_t len_password;
        in.read(reinterpret_cast<char*>(&len_password), sizeof(len_password));
        _password.resize(len_password);
        in.read(&_password[0], len_password);
    }

    bool checknget(std::ifstream& in)
    {
        Passenger temp;
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
        std::cout << "Email: " << _mail << "\n";
        std::cout << "Password: " << _password << "\n";
    }
};