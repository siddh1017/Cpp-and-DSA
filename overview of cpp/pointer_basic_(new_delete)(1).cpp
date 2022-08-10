#include <iostream>
using namespace std;

int main()
{
    int p = 10;
    int *ptr = &p;



    cout << "The value of ptr and &ptr is " << ptr << " " << &ptr << endl;
    cout << "The value of *ptr and p is " << p << " " << *(ptr) << endl;

    // new operator
    int *i = new int (123);
    cout << "the value at address i is " << *(i) << endl;
    
    int* arr = new int[3];
    
    for (int i=0; i<3; i++)
    {
        cin >> arr[i];
    }
    
    for (int i=0; i<3; i++)
    {
        cout << arr[i] << " ";
    }
    
    
    int* ary = new int[3];
    for (int i=0; i<3; i++)
    {
        cin >> *(ary + i); // another way to assign 
    }
    for (int i=0; i<3; i++)
    {
        cout << *(ary + i) << " ";
    }

    // delete operator
    delete arr;
    return 0;
}