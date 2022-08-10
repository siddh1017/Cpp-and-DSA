#include <iostream>
using namespace std;

// class complex
// {
//     int a, b;

// public:
//     void set(int n1, int n2)
//     {
//         a = n1;
//         b = n2;
//     }
//     void print()
//     {
//         cout << "complex no. is " << a << " + i" << b << endl;
//     }
//     friend complex sum(complex o1, complex o2);
// };
// complex sum(complex o1, complex o2)
// {
//     complex o3;
//     o3.set((o1.a + o2.a), (o1.b + o2.b));
//     return o3;
// }
// int main()
// {
//     complex o1, o2, value;
//     o1.set(1, 2);
//     o2.set(2, 3);
//     value = sum(o1, o2);
//     value.print();
//     return 0;
// }

// function which is friend of 2 class --------------------------->

// class Y; // saying compiler existing of class Y
// class X
// {
//     int data;

// public:
//     void setValue(int value)
//     {
//         data = value;
//     }
//     friend void sum(X, Y); // declaring sum as friend which takes the two objects X and Y as arguments
// };

// class Y
// {
//     int num;

// public:
//     void setValue(int value)
//     {
//         num = value;
//     }
//     friend void sum(X, Y);
// };

// void sum(X x, Y y)
// {
//     cout << "The sum is " << (x.data + y.num);
// }

// int main()
// {
//     X a;
//     a.setValue(2);

//     Y b;
//     b.setValue(3);

//     sum(a, b);
//     return 0;
// }

// 2 class as friend and some refreence mixing------------------>
// swaping values between 2 class
class Y; // saying compiler existing of class Y
class X
{
    int data;

public:
    void setValue(int value)
    {
        data = value;
    }
    int write()
    {
        return data;
    }
    friend void swap(X &, Y &); // declaring sum as friend which takes the two objects X and Y as arguments
};

class Y
{
    int num;

public:
    void setValue(int value)
    {
        num = value;
    }
    int write()
    {
        return num;
    }
    friend void swap(X &, Y &);
};

void swap(X &x, Y &y)
{
    int temp = x.data;
    x.data = y.num;
    y.num = temp;
}

int main()
{
    X a;
    a.setValue(2);

    Y b;
    b.setValue(3);

    cout << "Before swaping " << a.write() << " " << b.write() << endl;
    swap(a, b);
    cout << "After swaping " << a.write() << " " << b.write();
    return 0;
}