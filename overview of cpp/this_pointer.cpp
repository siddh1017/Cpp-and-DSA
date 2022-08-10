#include <iostream>
using namespace std;

class p_this
{
    int a;
    public:
    void setData(int a)
    {
        this->a = a;      
    }
    p_this& setData2 (int a)
    {
        this->a = a;
        return *this; 
    }
    void getData(void)
    {
        cout << "The value of a is " << a << endl;     
    }
};

int main()
{
    p_this p, p1;
    p1.setData2(14).getData();
    p.setData(12);
    p.getData();
    return 0;
}