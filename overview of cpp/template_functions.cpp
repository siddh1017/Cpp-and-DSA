// use template fynction when we have to deal with the diff type of datatypes

#include <iostream>
using namespace std;

template <class T1, class T2>
float average(T1 a, T2 b)
{
    float avg = (a + b) / 2;
    return avg;
}

template <class T>
void Swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
void display(T a)
{
    cout << "I am templatized diplay " << a << endl;
}
void display(int a)
{
    cout << "I am normal display " << a << endl;
}

int main()
{
    float a = average(2.5 , 7);
    cout << "The average is " << a << endl;
    float b = average(2 , 7);
    cout << "The average is " << b << endl;
    float c = average(2.5 , 7.34);
    cout << "The average is " << c << endl;
    
    float x=1, y=2;
    cout << "Before swap " << x << " " << y << endl;
    Swap (x, y);
    cout << "After swap " << x << " " << y << endl;

    display(4); // it gives first reference to the most exact same one...so it called non template function
    display(4.5);

    return 0;
}