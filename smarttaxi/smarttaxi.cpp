#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<fstream>
#include<cassert>
#include<sstream>
#include "Driver.h"
#include "Passenger.h"
#include "car.h"


enum op_1
{
    Register=1,
    Sign_in,
    Exit
};

class Order
{
protected:
    float _price;
    int _distance;
    std::string _place;
public:
    void SetPlace(std::string place)
    {
        _place = place;
    }

    void SetDistance(int distance)
    {
        _distance = distance;
    }
    void SetPrice(float price)
    {
        _price = price;
    }

    void WriteToFile(std::ofstream& filename)
    {
        size_t len_place = _place.size();
        filename.write(reinterpret_cast<const char*>(&len_place), sizeof(len_place));
        filename.write(&_place[0], len_place);
        filename.write(reinterpret_cast<const char*>(&_distance), sizeof(_distance));
        filename.write(reinterpret_cast<const char*>(&_price), sizeof(_price));
    }

    void ReadFromFile(std::ifstream& filename)
    {
        size_t len_surname;
        filename.read(reinterpret_cast<char*>(&len_surname), sizeof(len_surname));
        _place.resize(len_surname);
        filename.read(&_place[0], len_surname);

        filename.read(reinterpret_cast<char*>(&_distance), sizeof(_distance));
        filename.read(reinterpret_cast<char*>(&_price), sizeof(_price));
    }
    void print()  {
        std::cout << "Place: " << _place << "\n";
        std::cout << "Distance: " << _distance << "\n";
        std::cout << "Price: " << _price << "\n";
    }
};

int main()
{
    std::cout<<"            Are you\n";
    std::cout<<"A Driver    or     A Passenger\n";
    std::cout<<"Please Enter Your Choice:\n\n";
    std::cout<<"1.Driver\n2.Passenger\n";
    int choice;
    bool flag=false;
    while(flag==false)
    {
        try
        {
            std::cin>>choice;
            if(choice!=1 && choice!=2)
            {
                throw std::invalid_argument("Choose 1 or 2:\n");
            }
            else
            {
                flag=true;
            }
        }
        catch(std::invalid_argument& e)
        {
            std::cout<<e.what();
        }
    }
    if (choice==1)
    {
        bool flag=true;
        while(flag)
        {
            std::cout<<"Please Enter Your Choice:\n";
            std::cout<<"1.Register\n";
            std::cout<<"2.Sign in\n";
            std::cout<<"3.Exit\n";
            bool r_flag=false;
            int log;
            while(r_flag==false)
            {
                try
                {
                    std::cin>>log;
                    if(log!=1 && log!=2 && log!=3)
                    {
                        throw std::invalid_argument("Choose 1 or 2:\n");
                    }
                    else
                    {
                        r_flag=true;
                    }
                }
                catch(std::invalid_argument& e)
                {
                    std::cout<<e.what();
                }
            }
            
            switch (log){
                case Register:
                    {
                        Driver user;
                        std::string name;
                        std::string surname;
                        bool check_name=true;
                        bool check_surname=true;
                
                        while(check_name==true)
                        {
                            std::cout<<"Name:\n";
                            std::cin>>name;
                            bool has_digit=false;
                            for (auto element : name)
                            {                                    
                                if (element == '0' || element == '1' || element == '2' || element == '3' || element == '4' || element == '5' || element == '6' || element == '7' || element == '8' || element == '9')
                                {
                                    std::cout<<"Wrong name.Try again,please." << "\n";
                                    has_digit=true;
                                    break;
                                }
                            }
                            if(has_digit==false)
                            {
                                check_name=false;
                            }
                        }    
                        user.SetName(name);
                        while (check_surname==true)
                        {
                            std::cout<<"Surname:\n";
                            std::cin>>surname;
                            bool has_digit=false;
                            for (auto element : surname)
                            {                                    
                                if (element == '0' || element == '1' || element == '2' || element == '3' || element == '4' || element == '5' || element == '6' || element == '7' || element == '8' || element == '9')
                                {
                                    std::cout<<"Wrong surname.Try again,please." << "\n";
                                    has_digit=true;
                                    break;
                                }
                            }
                            if(has_digit==false)
                            {
                                check_surname=false;
                            }
                        }
                        user.SetSurname(surname);
                        std::cout<<"Age:";
                        int age;
                        flag=false;
                        while(flag==false)
                        {
                            std::cin>>age;
                            if (age>=18)
                            {
                                user.SetAge(age);
                                flag=true;
                            }
                            else
                            {
                                std::cout<<"\n";
                            }
                        }
                        std::cout<<"Mail:\n";
                        std::string mail;
                        bool mail_check=false;
                        while(mail_check==false)
                        {
                            std::string m="@gmail.com";
                            std::cin>>mail;
                            bool check_1=true,check_2=true;
                            int count=0;
                            for (auto element : mail)
                            {
                                if (element == '@')
                                {
                                    count+=1;
                                }
                                if (element == '#' || element == '%' || element == '&' || element == '*' || element == '(' || element == ')' || element == ' ' || element == '+' || element == '-' || element=='=' || element == '/')
                                {
                                    check_2=false;
                                }
                            }
                            if (count>1)
                            {
                                std::cout<<"Incorrect mail.Try again,please." << "\n";
                                check_1=false;
                            }
                            if (count==0)
                            {
                                mail+="@gmail.com";
                            }
                            if (check_1==true && check_2==true)
                            {
                                mail_check=true;
                            }
                                
                        }
                        user.SetMail(mail);
                        std::cout<<"Password:\n";
                        std::string password;
                        std::cin>>password;
                        user.SetPassword(password);
                        std::cout<<"License:\n";
                        int license;
                        std::cin>>license;
                        user.SetLicense(license);
                        std::cout<<"Car brand:\n";
                        std::string brand;
                        std::cin>>brand;
                        std::cout<<"Model:\n";
                        std::string model;
                        std::cin>>model;
                        std::cout<<"Year:\n";
                        int year;
                        std::cin>>year;
                        user.SetmyCar(brand,model,year);
                        std::cout<<"Class:\n1.Econom\n2.Comfort\n3.Business\n";
                        bool check_class=false;
                        while(check_class==false)
                        {
                            try
                            {
                                std::cin>>choice;
                                if(choice!=1 && choice!=2 && choice!=3)
                                {
                                    throw std::invalid_argument("Choose 1,2 or 3:\n");
                                }
                                else
                                {
                                    check_class=true;
                                }
                            }
                            catch(std::invalid_argument& e)
                            {
                                std::cout<<e.what();
                            }
                        }
                        switch (choice)
                        {
                        case 1:
                            user.SetClass("Econom");
                            break;
                        case 2:
                            user.SetClass("Comfort");
                            break;
                        case 3:
                            user.SetClass("Business");
                            break;
                        }
                        std::ofstream drivers_out("drivers_data",std::ios::binary|std::ios::app);
                        user.writeToFile(drivers_out);
                        
                        
                        flag=false;
                        break;
                    }    
                case Sign_in:
                    {
                        bool check_sign_in=false;
                        while (check_sign_in==false)
                        {
                                
                            Driver user;
                            std::cout<<"Enter Mail:\n";
                            std::string m;
                            std::cin>>m;
                            user.SetMail(m);
                            std::cout<<"Enter Password:\n";
                            std::string pwd;
                            std::cin>>pwd;
                            user.SetPassword(pwd);
                            std::ifstream drivers_in("drivers_data",std::ios::binary);
                            if (user.checknget(drivers_in))
                            {
                                user.print();    
                                check_sign_in=true;
                            }
                                
                            else
                            {
                                std::cout<<"Wrong password or mail.Try again,please.\n";
                                std::cout<<"Want to continue?\n";
                                std::cout<<"1.Yes\n2.No\n";
                                std::cin>>choice;
                                if (choice==2)
                                {
                                    check_sign_in=true;
                                }
                            }
                                
                        }
                        flag=false;
                        break;
                    }    
                case Exit:
                    {
                        flag=false;
                        break;
                    }        

            }
            
        }    
    }

    else if (choice==2)
    {
        bool flag=true;
        while(flag)
        {
            std::cout<<"Please Enter Your Choice:\n";
            std::cout<<"1.Register\n";
            std::cout<<"2.Sign in\n";
            std::cout<<"3.Exit\n";
            bool r_flag=false;
            int log;
            while(r_flag==false)
            {
                try
                {
                    std::cin>>log;
                    if(log!=1 && log!=2 && log!=3)
                    {
                        throw std::invalid_argument("Choose 1,2 or 3:\n");
                    }
                    else
                    {
                        r_flag=true;
                    }
                }
                catch(std::invalid_argument& e)
                {
                    std::cout<<e.what();
                }
            }
            
            switch (log){
                case Register:
                    {
                        Passenger user;
                        std::string name;
                        std::string surname;
                        bool check_name=true;
                        bool check_surname=true;
                
                        while(check_name==true)
                        {
                            std::cout<<"Name:\n";
                            std::cin>>name;
                            bool has_digit=false;
                            for (auto element : name)
                            {                                    
                                if (element == '0' || element == '1' || element == '2' || element == '3' || element == '4' || element == '5' || element == '6' || element == '7' || element == '8' || element == '9')
                                {
                                    std::cout<<"Wrong name.Try again,please." << "\n";
                                    has_digit=true;
                                    break;
                                }
                            }
                            if(has_digit==false)
                            {
                                check_name=false;
                            }
                        }    
                        user.SetName(name);
                        while (check_surname==true)
                        {
                            std::cout<<"Surname:\n";
                            std::cin>>surname;
                            bool has_digit=false;
                            for (auto element : surname)
                            {                                    
                                if (element == '0' || element == '1' || element == '2' || element == '3' || element == '4' || element == '5' || element == '6' || element == '7' || element == '8' || element == '9')
                                {
                                    std::cout<<"Wrong surname.Try again,please." << "\n";
                                    has_digit=true;
                                    break;
                                }
                            }
                            if(has_digit==false)
                            {
                                check_surname=false;
                            }
                        }
                        user.SetSurname(surname);
                        std::cout<<"Age:";
                        int age;
                        flag=false;
                        while(flag==false)
                        {
                            std::cin>>age;
                            if (age>=18)
                            {
                                user.SetAge(age);
                                flag=true;
                            }
                            else
                            {
                                std::cout<<"\n";
                            }
                        }
                        std::cout<<"Mail:\n";
                        std::string mail;
                        bool mail_check=false;
                        while(mail_check==false)
                        {
                            std::string m="@gmail.com";
                            std::cin>>mail;
                            bool check_1=true,check_2=true;
                            int count=0;
                            for (auto element : mail)
                            {
                                if (element == '@')
                                {
                                    count+=1;
                                }
                                if (element == '#' || element == '%' || element == '&' || element == '*' || element == '(' || element == ')' || element == ' ' || element == '+' || element == '-' || element=='=' || element == '/')
                                {
                                    check_2=false;
                                }
                            }
                            if (count>1)
                            {
                                std::cout<<"Incorrect mail.Try again,please." << "\n";
                                check_1=false;
                            }
                            if (count==0)
                            {
                                mail+="@gmail.com";
                            }
                            if (check_1==true && check_2==true)
                            {
                                mail_check=true;
                            }
                                
                        }
                        user.SetMail(mail);
                        std::cout<<"Password:\n";
                        std::string password;
                        std::cin>>password;
                        user.SetPassword(password);
                        std::ofstream clients_out("clients_data",std::ios::binary|std::ios::app);
                        user.writeToFile(clients_out);
                        std::ifstream drivers_in("drivers_data",std::ios::binary|std::ios::app);
                        Driver driver;
                        driver.readFromFile(drivers_in);
                        Order order;
                        std::cout<<"Make an Order:\n";
                        std::cout<<"Place:";
                        std::string place;
                        std::cin>>place;
                        order.SetPlace(place);
                        std::cout<<"\nDistance(in meters):";
                        int distance;
                        float price;
                        std::cin>>distance;
                        order.SetDistance(distance);
                        if (driver.GetClass()=="Econom")
                        {
                            price=distance*0.1;
                        }
                        else if (driver.GetClass()=="Comfort")
                        {
                            price=distance*0.25;
                        }
                        else if (driver.GetClass()=="Business")
                        {
                            price=distance*0.35;
                        }
                        order.SetPrice(price);
                        std::ofstream out_1("drivers_data",std::ios::binary|std::ios::app);
                        order.WriteToFile(out_1);
                        std::cout<<"\nPrice:"<<price;
                        float rate;
                        std::cout<<"\nRate him:";
                        std::cin>>rate;
                        driver.SetRating(rate);
                        std::ofstream out("drivers_data");
                        driver.writeToFile(out);
                        flag=false;
                        break;
                    }    
                case Sign_in:
                    {
                        bool check_sign_in=false;
                        while (check_sign_in==false)
                        {
                                
                            Passenger user;
                            std::cout<<"Enter Mail:\n";
                            std::string m;
                            std::cin>>m;
                            user.SetMail(m);
                            std::cout<<"Enter Password:\n";
                            std::string pwd;
                            std::cin>>pwd;
                            user.SetPassword(pwd);
                            std::ifstream clients_in("clients_data",std::ios::binary);
                            if (user.checknget(clients_in))
                            {
                                user.print();    
                                check_sign_in=true;
                            }
                                
                            else
                            {
                                std::cout<<"Wrong password or mail.Try again,please.\n";
                                std::cout<<"Want to continue?\n";
                                std::cout<<"1.Yes\n2.No\n";
                                std::cin>>choice;
                                if (choice==2)
                                {
                                    check_sign_in=true;
                                }
                            }
                                
                        }
                        std::ifstream drivers_in("drivers_data",std::ios::binary|std::ios::app);
                        Driver driver;
                        driver.readFromFile(drivers_in);
                        Order order;
                        std::cout<<"Make an Order:\n";
                        std::cout<<"Place:";
                        std::string place;
                        std::cin>>place;
                        order.SetPlace(place);
                        std::cout<<"\nDistance(in meters):";
                        int distance;
                        float price;
                        std::cin>>distance;
                        order.SetDistance(distance);
                        if (driver.GetClass()=="Econom")
                        {
                            price=distance*0.1;
                        }
                        else if (driver.GetClass()=="Comfort")
                        {
                            price=distance*0.25;
                        }
                        else if (driver.GetClass()=="Business")
                        {
                            price=distance*0.35;
                        }
                        order.SetPrice(price);
                        std::ofstream out_1("drivers_data",std::ios::binary|std::ios::app);
                        order.WriteToFile(out_1);
                        std::cout<<"\nPrice:"<<price;
                        float rate;
                        std::cout<<"\nRate him:";
                        std::cin>>rate;
                        driver.SetRating(rate);
                        std::ofstream out("drivers_data");
                        driver.writeToFile(out);
                        flag=false;
                        break;
                    }    
                case Exit:
                    {
                        flag=false;
                        break;
                    }        

            }
            
        }
    }

    return 0;
}