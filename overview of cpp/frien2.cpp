#include <iostream>

using namespace std;

// class a
// {
//     int b, c;

// public:
//     a()
//     {
//         b = 5;
//         c = 1;
//     }
//     friend int s(a &);
//     int write_b()
//     {
//         return b;
//     }
// };

// int s(a &o)
// {
//     o.b *= o.c;
//     o.b = o.b + o.c;
//     return o.b;
// }

// int main()
// {
//     a o;
//     cout << s(o) << " ";
//     cout << o.write_b();
//     return 0;
// }

class A
{
    int a;

public:
    A()
    {
        a = 1;
    }
    friend class B;
};

class B
{
    int b;

public:
    B()
    {
        b = 1;
    }
    int write(A obj)
    {
        return b + obj.a;
    }
};

int main()
{
    A a;
    B b;
    cout << b.write(a);
}