#include <iostream>
using namespace std;

class base1
{
    public:
    void greet(void)
    {
        cout << "Hello World" << endl;
    }
};

class base2
{
    public:
    void greet(void)
    {
        cout <<"Hi Everyone"  << endl;
    }
};

class derived : public base1 , public base2
{
    public:
    void greet()
    {
        base1 :: greet();
    }
};

class A
{
    public:
    void bolo()
    {
        cout << "Hi dear" << endl;
    }
};

class B : public A
{
    public:
    void bolo()
    {
        cout << "Hello dear" << endl;
    }  
};

class C : public A
{

};

int main()
{
    derived d;
    d.greet();   // this will give an error as compiler will get confused that from which base class greet  is to be inherited if line 27 is not writeen 


    A a;
    B b;
    C c;
    a.bolo();    // this will use class A bolo()
    b.bolo();    // this will use class B bolo() and will not give ambiguity error as it has its own
    c.bolo();    // it will inherit bolo() from class A
    return 0;
}