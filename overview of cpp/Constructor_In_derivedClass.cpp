#include <iostream>
using namespace std;

/*
Case1:
class B : public class A{
    // then first A() then B() is called
}

Case2:
class A : public B, public C{
    // then B() -> C() -> A() are called
}

case3:
class A : public B, virtaul public C{
    // then C() -> B() -> A() are called
}

*/

class base1
{

private:
    int b1;

public:
    base1 (int x)
    {
        b1=x;
        cout << "The base1 constructor is called" << endl;
    }
    void printData()
    {
        cout << "The value of base1 -> b1 " << b1 << endl;
    }
};

class base2
{
    private:
    int b2;
    public:
    base2 (int x)
    {
        b2=x;
        cout << "The base2 constructor is called " << endl;
    }
    void printData()
    {
        cout << "The value of base2 -> b2 " << b2 << endl;
    }
};

class derived : public base1 , public base2
{
    private:
    int d1, d2;
    public:
    derived (int a, int b, int c, int d) : base1(a), base2 (b)
    {
        d1=c; d2=d;
        cout << "The derived constructor is called" << endl;
    }
    void printData (void)
    {
        base1 :: printData();
        base2 :: printData();
        
        cout << "The value of d1 is " << d1 << endl;
        cout << "The value of d2 is " << d2 << endl;
    }
};
int main()
{
    derived d(1,2,3,4);
    d.printData();
    
    return 0;
}
