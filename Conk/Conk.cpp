#include <iostream>
#include <fstream>
#include <string>

class User
{
protected:
    std::string _name,_surname,_mail,_password;
    int _age;
public:
    User()
    {
        
    }

    User& operator=(const User& other)
    {
        if (this != &other)
        {
            _name = other._name;
            _surname= other._surname;
            _mail = other._mail;
            _password = other._password;
            _age = other._age;
        }
        return *this;
    }

    
    User(const User& other): _name(other._name), _mail(other._mail), _password(other._password), _age(other._age)
    {
        
    }
    void SetName(std::string name)
    {
        _name = name;
    }
    std::string GetName()
    {
        return _name;
    }
    void SetSurname(std::string surname)
    {
        _surname = surname;
    }
    std::string GetSurame()
    {
        return _surname;
    }
    void SetAge(int age)
    {
        _age = age;
    }
    int GetAge()
    {
        return _age;
    }
    void SetPassword(std::string password)
    {
        _password = password;
    }
    void SetMail(std::string mail)
    {
        _mail = mail;
    }
    std::string GetMail()
    {
        return _mail;
    }

    std::string GetPassword()
    {
        return _password;
    }
};

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

class Driver : public User
{
protected:
    int _license;
    float _rating;
    std::string _class;
    Car _myCar;
public:
    Driver()
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

class Passenger : public User
{
public:
    Passenger& operator=(const Passenger& other)
    {
        if (this != &other)
        {
            User::operator=(other);  
        }
        return *this;
    }

};

class System
{
protected:
    Passenger* plist=new Passenger[0]();
    int pcount=0;
    Driver* dlist=new Driver[0]();
    int dcount=0;
public:
    
};





int main() {
    // Driver d;
    // std::ofstream out("per", std::ios::binary);
    // d.SetmyCar("wd","as",12);
    // d.SetLicense(12);
    // d.SetAge(21);
    // d.SetName("wd");
    // d.SetSurname("dwd");
    // d.SetMail("a@gmail.com");
    // d.SetPassword("wew");
    // d.writeToFile(out);
    Driver test;
    std::ifstream in("per", std::ios::binary);
    test.readFromFile(in);
    
    test.print();
    
    
    return 0;
}

// void readFromFile(std::ifstream& in) {
//     size_t len;
//     in.read(reinterpret_cast<char*>(&len), sizeof(len));
//     name = std::string(len, '\0');
//     in.read(&name[0], len);
//     in.read(reinterpret_cast<char*>(&age), sizeof(age));
//
//     address.readFromFile(in);
// }


// Address address("a",2);
// Person person("Bagdagul", 3, address);
// std::ofstream out("per", std::ios::binary);
// person.writeToFile(out);

// std::ifstream in("per", std::ios::binary);
// Person person2;
// person2.readFromFile(in);
//
// person2.print();