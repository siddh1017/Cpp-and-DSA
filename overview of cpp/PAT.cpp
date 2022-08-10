#include <iostream>
using namespace std;

static int count=1;

class employee
{
    string name;
    int hours[5];
    int minutes[5];
    
    public:
    employee()
    {
        cin >> name;
        for (int i=0; i<5; i++)
        {
            cin >> hours[i] >> minutes[i];
        }
    }
     friend void late (int , int, employee e[]);
};

void late(int h, int m, employee e[])
{
    for (int i=0; i<5; i++)
    {
       if (e[i].hours[i]>h && e[i+1].hours[i]>h)
       {
           
       }
    }
}

int main()
{
    int n;
    cin >> n;
    employee e[n];
    
    int expected_h, expected_m;
    cin >> expected_h >> expected_m;
    
    for (int i=0; i<5; i++)
    {
        late(expected_h , expected_m, e[i]);
    }
    
    return 0;
}