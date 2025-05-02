#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Animal
{
protected:
    char _name[20];
    int _age;
    double _weight;
public:
    Animal() :_name(""), _age(0), _weight(0) {

    }
    Animal(const char* name, int age, double weight)
    {
        for (int i = 0; i < 20; i++)
        {
            _name[i] = name[i];
        }
        _age = age;
        _weight = weight;
    }
    char* GetName()
    {
        return &_name[0];
    }
    int GetAge()
    {
        return _age;
    }
    double GetWeight()
    {
        return _weight;
    }
    void printInfo()
    {
        std::cout << "Name: " << GetName() << std::endl;
        std::cout << "Age: " << GetAge() << std::endl;
        std::cout << "Weight: " << GetWeight() << std::endl;
    }
};

class Mammal : public Animal
{
protected:
    bool _HasFur;
public:
    Mammal(const char* name, int age, double weight) : Animal(name, age, weight)
    {
        for (int i = 0; i < 20; i++)
        {
            _name[i] = name[i];
        }
        _age = age;
        _weight = weight;
    }
    void SetFur(bool HasFur)
    {
        _HasFur = HasFur;
    }
    bool GetHasFur()
    {
        return _HasFur;
    }
};

class Bird : public Animal
{
protected:
    double _wingSpan;
public:
    Bird(const char* name, int age, double weight) : Animal(name, age, weight)
    {
        for (int i = 0; i < 20; i++)
        {
            _name[i] = name[i];
        }
        _age = age;
        _weight = weight;
    }
    void SetwingSpan(double wingSpan)
    {
        _wingSpan = wingSpan;
    }
    double GetwingSpan()
    {
        return _wingSpan;
    }
};

class Reptile : public Animal
{
protected:
    bool _isVenomous;
public:
    Reptile(const char* name, int age, double weight) : Animal(name, age, weight)
    {
        for (int i = 0; i < 20; i++)
        {
            _name[i] = name[i];
        }
        _age = age;
        _weight = weight;
    }
    void SetisVenomous(bool isVenomous)
    {
        _isVenomous = isVenomous;
    }
    bool GetisVenomous()
    {
        return _isVenomous;
    }
};

class ZooWorker
{
protected:
    char _name[20];
    int _experience;
public:
    ZooWorker() :_name(""), _experience(0) {

    }
    ZooWorker(const char* name, int experience)
    {
        for (int i = 0; i < 20; i++)
        {
            _name[i] = name[i];
        }
        _experience = experience;
    }


    void SetName(const char* name)
    {
        for (int i = 0; i < 20; i++)
        {
            _name[i] = name[i];
        }
    }
    void SetExperience(int experience)
    {
        _experience = experience;
    }
    char* GetName()
    {
        return &_name[0];
    }
    int GetExperience()
    {
        return _experience;
    }
    void printInfo()
    {
        std::cout << "Name: " << GetName() << std::endl;
        std::cout << "Experience: " << GetExperience() << std::endl;
    }
};

class Enclosure 
{
protected:
    char _type[20];
    int _capacity;
    Animal* _animals[10];
    int _animalCount;
    ZooWorker _caretaker;
public:
    Enclosure(): _type(""),_capacity(0) {
        _caretaker.SetName("");
        _caretaker.SetExperience(0);
    }
    Enclosure(const char* type, int capacity, const char* name, int experience) : _caretaker(name, experience)
    {
        for (int i = 0; i < 10; i++)
        {
            _type[i] = type[i];
        }
        _capacity = capacity;
        _animals[10] = _animals[_capacity];
        _animalCount = 0;
        _caretaker.SetName(name);
        _caretaker.SetExperience(experience);
    }
    void SetType(const char* type)
    {
        for (int i = 0; i < 20; i++)
        {
            _type[i] = type[i];
        }
    }

    char* GetType()
    {
        return &_type[0];
    }
    int GetCapacity()
    {
        return _capacity;
    }
    char* Lol()
    {
        return _caretaker.GetName();
    }
    void addAnimal(Animal* animal)
    {
        _animals[_animalCount] = animal;
        _animalCount += 1;
    }
    void removeAnimal(int index)
    {
        Animal* temp = _animals[index];
        _animals[index] = _animals[0];
        _animals[0] = temp;
        for (int i = 0; i < _animalCount; i++) {
            _animals[i] = _animals[i + 1];
        }
        _animalCount -= 1;
    }
    
    void PrintEnclosureInfo() {
        std::cout << "Caretaker: " << _caretaker.GetName() << std::endl;
        std::cout << "Experience: " << _caretaker.GetExperience() << std::endl;
        std::cout << "Enclosure Type: " << _type << std::endl;
        std::cout << "Capacity: " << _capacity << std::endl;
        std::cout << "Animals in Enclosure: " << std::endl;
        for (int i = 0; i < _animalCount; i++) {
            std::cout << _animals[i]->GetName() << std::endl;
        }
    }
};

class Zoo : public Enclosure
{
protected:
    Enclosure _enclosures[5];
    int _enclosureCount;
public:
    Zoo()  {
        _enclosureCount = 0;
        for (int i = 0; i < 5; i++) {
            _enclosures[i] = Enclosure();
        }
    }
    Zoo(const char* type, int capacity, const char* name, int experience) : Enclosure(type, capacity, name, experience) {
            _enclosureCount = 0;
            for (int i = 0; i < 5; i++) {
                _enclosures[i]=Enclosure(type,capacity,name,experience);
            }
    }
    void addEnclosure(Enclosure enclosure) {
        if (_enclosureCount < 5) {
            _enclosures[_enclosureCount] = enclosure;
            _enclosureCount++;
        }
    }
    void PrintZooInfo()
    {
        std::cout << "Zoo Information:" << std::endl;
        for (int i = 0; i < _enclosureCount; i++) {
            std::cout << "Enclosure " << (i + 1) << " Info:" << std::endl;
            _enclosures[i].PrintEnclosureInfo();
            std::cout << std::endl;
        }
    }
};

int main() {
    Mammal dolphin("Dolphin", 25, 170);
    dolphin.SetFur(false);
    std::cout << dolphin.GetHasFur() << std::endl;
    dolphin.printInfo();
    Bird eagle("Eagle", 22, 4);
    eagle.SetwingSpan(2.1);
    std::cout << eagle.GetwingSpan() << std::endl;
    eagle.printInfo();
    Reptile king_cobra("King Cobra", 20, 7);
    king_cobra.SetisVenomous(true);
    std::cout << king_cobra.GetisVenomous() << std::endl;
    king_cobra.printInfo();
    ZooWorker worker("Bagdagul", 10);
    worker.printInfo();
    Enclosure enclosure("Savannah", 10, "nihad", 15);
    enclosure.addAnimal(&king_cobra);
    enclosure.addAnimal(&eagle);
    enclosure.addAnimal(&dolphin);
    enclosure.removeAnimal(1);
    enclosure.PrintEnclosureInfo();
    Zoo zoo;
    zoo.addEnclosure(enclosure);
    zoo.PrintZooInfo();
    return 0;
}
