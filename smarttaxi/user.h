#pragma once
#include <string>

class User {
protected:
    std::string _name, _surname, _mail, _password;
    int _age;

public:
    User() = default;
    User(const User& other) = default;
    User& operator=(const User& other) = default;

    void SetName(std::string name) { _name = name; }
    std::string GetName() { return _name; }

    void SetSurname(std::string surname) { _surname = surname; }
    std::string GetSurname() { return _surname; }

    void SetAge(int age) { _age = age; }
    int GetAge() { return _age; }

    void SetPassword(std::string password) { _password = password; }
    std::string GetPassword() { return _password; }

    void SetMail(std::string mail) { _mail = mail; }
    std::string GetMail() { return _mail; }
};