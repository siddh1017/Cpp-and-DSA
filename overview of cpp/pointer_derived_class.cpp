#include <iostream>
using namespace std;

class base
{
public:
    int bas;
    void display(void)
    {
        cout << "The value of base class variable is " << bas << endl;
    }
};

class derived : public base
{
public:
    int derivd;
    void display(void)
    {
        cout << "the value of derived class varaible is " << derivd << endl;
        cout << "The value of base variable is "<< bas << endl;
    }
};

int main()
{
    base * b_pointer;
    base b_simple;
    derived d_simple;

    b_pointer = &d_simple; //pointing the base class pointer to derived class  

    b_pointer->bas = 123;
    // b_pointer->derivd = 345; //  this will give an error

    b_pointer->display();

    derived* d_pointer;
    d_pointer = &d_simple;

    d_pointer->bas = 456; 
    d_pointer->derivd = 123;
    d_pointer->display();

    return 0;
}