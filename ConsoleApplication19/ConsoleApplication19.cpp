#include <iostream>
#include <memory>

class Biba
{
public:
    int test = 5;
    Biba() { std::cout<<"Biba"<<std::endl;}
    ~Biba() { std::cout<<"~Biba"<<std::endl;}

    void sayHello()
    {
        std::cout<<"Hello world!"<< '\n';
    }
};

template <typename T>
class u_ptr
{
private:
    T _ptr;
public:
    u_ptr()
    {
        
    }
    ~u_ptr()
    {
        std::cout<<"~u_ptr"<<std::endl;
    }
    
};

int main()
{
    // std::shared_ptr<Biba> biba_shared_ptr = std::make_shared<Biba>();
    // std::shared_ptr<Biba> biba_shared_ptr_2 = biba_shared_ptr;
    // std::shared_ptr<Biba> biba_shared_ptr_3 = biba_shared_ptr_2;
    // std::shared_ptr<Biba> biba_shared_ptr_4 = biba_shared_ptr_3;
    //
    // biba_shared_ptr_2->test = 2;
    //
    // std::cout<<biba_shared_ptr_4->test;
    //
    // std::unique_ptr<int[]> biba_ptr = std::make_unique<int[]>(5);
    // biba_ptr[0] = 1;
    // biba_ptr[1] = 2;
    // biba_ptr[2] = 3;
    // biba_ptr[3] = 4;
    // biba_ptr[4] = 5;
    //
    // for (int i = 0; i < 5; ++i)
    // {
    //     std::cout<<biba_ptr[i]<<'\n';
    // }
    //
    // if (!biba_ptr)
    // {
    //     std::cout<<"nullptr"<<std::endl;
    // }
    int a=5;
    u_ptr<Biba> uno();
    
    
    return 0;
}
