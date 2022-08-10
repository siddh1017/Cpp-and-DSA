/*
1. PRIVATE members of the class  cannot be inherited

2. When the class is inherited in PRIVATE mode then all members OF that base class act as PRIVATE for that particular DERIVED class.....that is cannot be called or used directly from main class

3. When the class is inherited in PUBLIC mode then all members OF that base class act as public (except the private and protected members, already declared in base class) for that particular DERIVED class

4. When the variable or function is declared PROTECTED then DERIVED class can have access over that in PROTECTED mode only....but that protected members can not be accessed by main class

*/


// <----SINGLE INHEITENCE TYPE----->


#include <iostream>

using namespace std;

class base
{
    private:
    int x;
    protected:
    int y=100;
    void print ()
    {
        cout << "I am under base protection" << endl;
    }
    public:
    int z;
    void setBase()
    {
        x=1; y=2; z=3;
        cout  << x << " " << y << " " << z << endl;
    }
};

class derived : private base
{
    // int a;
    
    public:
    int a=10;
    void set()
    {
        cin >> y;
        z=10;
    }
};

// class derived2 : public derived
// {
//     public:
//     void dev (obj)
//     {
//         obj.setDerived();
//     }
// };
int main()
{
    base b1;
    b1.setBase();
    derived d1;
    d1.set();
    // cout << d1.z; this will give error as derived class inherited privately
    // cout << b1.y;  this will give error as it is protected under base.....but derived class can asses it (in line 39)
    cout << d1.a;
    return 0;
}