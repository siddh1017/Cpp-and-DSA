#include <iostream>
using namespace std;

class base 
{
    public:
        int b = 1;
        virtual void display(void)
        {
            cout << "The value of the base b is " << b << endl;
        }
};

class derived : public base
{
    public:
        int d=2;
        void display(void)
        {
            cout  << "The value of derived d is " << d << endl;
        }
};
class derived2 : public derived
{
    public:
        int d2=3;
        void display(void)
        {
            cout << "The value of derived 2 d2 is " << d2 << endl;
        }
};

int main()
{
    base* b_pointer;
    derived d;
    b_pointer = &d;

    b_pointer->display();
    derived* d_pointer;

    derived2 dev2;
    d_pointer = &dev2;
    d_pointer->display();
    return 0;
}