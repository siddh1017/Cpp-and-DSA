#include <iostream>
#include <cmath>
using namespace std;

// class point
// {
//     int x, y;

// public:
//     point()
//     {
//         cout << "Enter the value of x ";
//         cin >> x;
//         cout << "Enter the value of y ";
//         cin >> y;
//     }
//     friend void distance(point, point);
// };

// void distance(point a, point b)
// {
//     float value;
//     value = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
//     cout << "The distance betweeen 2 points is " << value;
// }

// int main()
// {
//     point a, b;
//     distance(a, b);
//     return 0;
// }

// constructors overloading
// class complex
// {
//     int a, b;
//     public:
//     complex()
//     {
//         a=0; b=0;
//     }
//     complex(int x)
//     {
//         a=x; b=0;
//     }
//     complex(int x, int y)
//     {
//         a=x ; b=y;
//     }
//     // complex (int x, int y=9)
//     // {
//     //     a=x; b=y;
//     // }
//     void print()
//     {
//         cout << "a=" << a << " and b=" << b << endl;
//     }
// };

// int main()
// {
//     complex p1, p2(4), p4(1,5);
//     p1.print();
//     p2.print();
//     p4.print();
// }

// One IMPORTANT Point--------------------->
// class point
// {
//     int a;

// public:
//     point() {} /* if this constructor is not created
//                we will be not able to create object as created below*/

//     point(int x)
//     {
//         cout << "The int point is called with value " << x << endl;
//     }
//     point(double x)
//     {
//         cout << "The float point is called with value " << x;
//     }
// };

// int main()
// {
//     point p1(1), p2(0.2), p3; // p3 will raise an errror if line 75 is not written 
// }

// THINGS ABOUT COPY CONSTRUCTORS ------------------>

class point
{
    int a;

public:
    point(int x = 1)
    {
        a = x;
    }
    void print()
    {
        cout << "The value is " << a << endl;
    }

    // This will be invoked when a copy constructor is made
    point(point &obj)
    {
        cout << "The copy constructer is invoked!!" << endl;
        a = obj.a;
    }
};

int main()
{
    point p1, p2(10), p3, p5;

    p1.print();
    p2.print();
    p3.print();
    point p4 = p2;
    p4.print();
    p5 = p2;
    p5.print();

}