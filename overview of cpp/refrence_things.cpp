#include <iostream>

using namespace std;
 // call by value
void swap(int a, int b)
{
    int temp=a;
    a=b;
    b=temp;
}
 // call by refrence pointer
void swapByPointer(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
 // call by refrence
void swapByRefrence(int& a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
}
 // function returning the refrence value
int& swapByRefrence1(int& a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
    return a;
}

int main()
{
    int x=5, y=10;
    
    cout<< " Normal swap"<<endl;
    cout<<"initiallty x="<< x<<" and y="<< y<< endl;
    swap(x,y);
    cout<<"finally x="<< x<<" and y="<< y<<endl;
    cout<<endl;

    // cout<<" swap by pointer"<<endl;
    // cout<<"initiallty x="<< x<<" and y="<< y<< endl;
    // swapByPointer(&x, &y);
    // cout<<"finally x="<< x<<" and y="<< y;
    // cout<<endl;

    // cout<< " swap by refrence"<<endl;
    // cout<<"initiallty x="<< x<<" and y="<< y<< endl;
    // swapByRefrence(x,y);
    // cout<<"finally x="<< x<<" and y="<< y<<endl;

    cout<< " swap by refrence"<<endl;
    cout<<"initiallty x="<< x<<" and y="<< y<< endl;
    swapByRefrence1(x,y)=23;
    cout<<"finally x="<< x<<" and y="<< y<<endl;
    
    return 0;
}

// int main()
// {
//     int a=5;
//     int& y=a;
//     cout<<y;
//     return 0;

// }