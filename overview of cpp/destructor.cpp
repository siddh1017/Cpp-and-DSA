#include <iostream>
using namespace std;

int count = 1;

class point 
{
    public:
    point()
    {
        cout << "Constructor is called of object " << count<< endl;
        count++;
    }
    ~point()
    {
        count--; 
        cout << "Destructor is called for object " <<count<< endl;
    }
};

int main()
{
    cout << "I'm in main block"<< endl;
    point p1;
    {
        cout << "I entered the sub block"<< endl;
        point p2, p3;
        cout << "I'm leaving sub block after creating p2 and p3"<< endl;
    }
    cout << "I'm back in main block"<< endl;
    return 0;
}