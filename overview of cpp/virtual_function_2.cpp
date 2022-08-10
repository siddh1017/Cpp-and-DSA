#include <iostream>
using namespace std;

class base 
{
    protected:
        int b;
    public:
        base (int a)
        {
            b = a;
        }
        virtual void display(void)
        {
            cout << "Call from base class" << endl;
        } 
};

class derived1 :public base
{
        int dev1;
    public:
        derived1 (int a, int d1) : base (a)
        {
            dev1 = d1;
        }
        void display (void)
        {
            cout << "The value of base varaible is " << b << endl;
            cout << "The value of derived1 varaible is " << dev1 << endl << endl;
        }
};

class derived2 :public base
{
        int dev2;
    public:
        derived2 (int a, int d2) : base (a)
        {
            dev2 = d2;
        }
        void display (void)
        {
            cout << "The value of base varaible is " << b << endl;
            cout << "The value of derived2 varaible is " << dev2 << endl;
        }
};

class derived3 :public base
{
        int dev3;
    public:
        derived3 (int a, int d3) : base (a)
        {
            dev3 = d3;
        }
        // void display (void)
        // {
        //     cout << "The value of base varaible is " << b << endl;
        //     cout << "The value of derived3 varaible is " << dev3 << endl;
        // }
};

int main()
{
    derived1 d1 (10, 20);
    derived2 d2 (11, 21);
    derived3 d3 (13, 22);

    base* a[3];

    a[0] = &d1;
    a[0]->display();

    a[1] = &d2;
    a[1]->display();

    a[2] = &d3;
    a[2]->display();
    // if the any of the derived class has no defined display function then BASE class display is called.

    return 0;
}

// Some Points about virtual function
// 1. They are non-static
// 2. Are accessed by object pointes 
// 3. They can be a friend of other class
// 4. The base class virtual function may cannot be used
