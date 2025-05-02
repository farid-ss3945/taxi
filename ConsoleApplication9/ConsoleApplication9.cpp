#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


enum MenuOption
{
    SHOW_STUDENS = 1,
    ADD_STUDENT,
    REMOVE_STUDENT,
    EXIT
};

struct Adress
{
    char country[20];
    char city[30];
    char street[30];

};

struct Student
{
    Adress adress;
    int id;
    char name[20];
    int age;
    int grade;
};

void printMenu();

void resizeArray(Student*& students, unsigned int& capacity,int factor);

Student input_Student();

Student fill_student();

bool add_student(Student*& students, unsigned int& capacity);

void showStudent(Student*& students, unsigned int& capacity);

bool remove(Student*& a, unsigned int& size,int id);

int main()
{
    unsigned int capacity = 1;
    
    int option;
    Student* students = new Student[capacity];
    students[0] = { .adress = {.country = "Niger",.city = "Niamei",.street = "Arlit"},.id = 1,.name = "baghdagul",.age = 15,.grade = 10 };
    while (true)
    {
        bool flag=true;
        printMenu();
        std::cout << "Option: " << '\n';
        std::cin >> option;
        std::cin.ignore();

        switch (option)
        {
        case SHOW_STUDENS:
            showStudent(students,capacity);
            break;
        case ADD_STUDENT:
            if (add_student(students,capacity))
            {
                std::cout << "Added student successfully.\n";
            }
            else
            {
                std::cout << "Wrong data.\n";
            }
            break;
        case REMOVE_STUDENT:
            int cid;
            std::cin>>cid;
            if(remove(students,capacity,cid))
            {
                std::cout << "Removed student successfully.\n";
            }
            else
            {
                std::cout << "No student with that id.\n";
            }
            break;
        case EXIT:
            flag=false;
            break;
        }
        if (!flag)
        {
            break;
        }
    }

    return 0;
}


void printMenu()
{
    std::cout << "----MENU----\n";
    std::cout << "1. Show Students" << '\n';
    std::cout << "2. Add student" << '\n';
    std::cout << "3. Remove student" << '\n';
    std::cout << "4. Exit" << '\n';
}

bool isValidStudent(Student st)
{
    if (st.age<5 || st.age>20 || st.grade<1 || st.grade>11)
    {
        return false;
    }
    return true;
}

Student input_Student()
{
    Adress adress;
    Student temp;
    // int age, grade,id;
    std::cin>>adress.country>>adress.city>>adress.street;
    std::cin>>temp.id>>temp.grade>>temp.age>>temp.name;
    strncpy(temp.adress.country,adress.country,20);
    strncpy(temp.adress.city,adress.city,30);
    strncpy(temp.adress.street,adress.street,30);
    strncpy(temp.name,temp.name,20);
    temp.adress = adress;
    return temp;
    
}


Student fill_student()
{
    
    return input_Student();
}

bool add_student(Student*& students, unsigned int& capacity)
{
    Student t=fill_student();
    if (isValidStudent(t)==true)
    {
        resizeArray(students, capacity,1);
        students[capacity-1]=t;
        return true;
    }
    else
    {
        return false;
    }
}

void resizeArray(Student*& students, unsigned int& capacity,int factor)
{
    unsigned int newCapacity = capacity + factor;
    Student* studentsTemp = new Student[newCapacity];
    for (int i = 0; i < capacity; i++)
    {
        studentsTemp[i] = students[i];
    }
    delete[] students;
    students = studentsTemp;
    capacity = newCapacity;
}
void showStudent(Student*& students, unsigned int& capacity)
{
    for (int i = 0;i < capacity; i++)
    {
        std::cout << "Student ID: " << students[i].id << ", Name: " << students[i].name << ", Age: " << students[i].age << ", Grade: " << students[i].grade << '\n';
        std::cout << "Country: " << students[i].adress.country << ", City: " << students[i].adress.city << ", Street: " << students[i].adress.street << '\n';
    }
}
bool remove(Student*& a, unsigned int& size,int id) {
    int index;
    for (int i = 0; i < size; i++)
    {
        if (a[i].id==id)
        {
            index = i;
            Student* temp_arr = new Student[size - 1];
            for (size_t i = 0; i < index; i++)
            {
                temp_arr[i] = a[i];
            }
            for (size_t i = index; i < size-1; i++)
            {
                temp_arr[i] = a[i+1];
            }
            delete[] a;
            a = temp_arr;
            size--;
            return true;
        }
    }
    return false;
}