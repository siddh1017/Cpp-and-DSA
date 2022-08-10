#include <iostream>
using namespace std;

class base1
{
    protected:
    int a;
    public:
    void setbase1(int x)
    {
        a=x;
    }
};

class base2
{
    protected:
    int b;
    public:
    void setbase2(int y)
    {
        b=y;
    }
};

class derived : public base1 ,public base2
{
    int sum;
    public:
    void result (void)
    {
        sum = a+b;
        cout << sum;
    }
};


/*
for derived class 
setbase1 , setbase2 ----> public mode
result ----> public mode
a,b ----> protected mode
*/

int main()
{
    derived d;
    d.setbase1(100);
    d.setbase2(1);
    d.result();
    return 0;
}