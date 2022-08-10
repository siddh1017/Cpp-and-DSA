#include <iostream>
using namespace std;

// creating the abstract class, which is the base class of every derived class containting atleast one PURE VIRTUAL FUNCTION.

class abstract // can use any name
{
    protected:
        int abs;
    public:
        abstract (int a)
        {
            abs = a;
        }
        virtual void display(void)=0; // declaring the display function as pure virtual function
        // it means it is mandatory that we are supposed to define display function in every derived class 
};

class derived1 :public abstract
{
        int dev1;
    public:
        derived1 (int a, int d1) : abstract (a)
        {
            dev1 = d1;
        }
        void display (void)
        {
            cout << "The value of abstract varaible is " << abs << endl;
            cout << "The value of derived1 varaible is " << dev1 << endl << endl;
        }
};

class derived2 :public abstract
{
        int dev2;
    public:
        derived2 (int a, int d2) : abstract (a)
        {
            dev2 = d2;
        }
        void display (void)
        {
            cout << "The value of abstract varaible is " << abs << endl;
            cout << "The value of derived2 varaible is " << dev2 << endl;
        }
};

int main()
{
    derived1 d1 (10, 20);
    derived2 d2 (11, 21);

    abstract* a[2];

    a[0] = &d1;
    a[0]->display();

    a[1] = &d2;
    a[1]->display();

    return 0;
}
