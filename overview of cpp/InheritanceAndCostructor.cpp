#include <iostream>
using namespace std;

class base
{
private:
    int a;

public:
    base() 
    { 
        "base constructor is called"; 
    }
    base(int x)
    {
        cout << "base constructor is called" << endl;
        a = x;
        cout << x << endl;
    }
};

class derived : public base
{
private:
    int b;

public:
    derived(int y, int x) : base (x)
    {
        cout << "derived constructor is called" << endl;
        b = y;
        cout << y << endl;
    }
};

int main()
{

    derived d(12,13);
    return 0;
}