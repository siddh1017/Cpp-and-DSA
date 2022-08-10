#include <iostream>
#include <stdio.h>
using namespace std;

class time
{
    public:
    int hours, min, sec;
    time()
    {
        hours=0; min=0; sec=0;
    }
    void read()
    {
        cin>>hours>>min>>sec;
    }
};


int main()
{
    time t1;
    time t2;
    time t3;
    t1.read();
    t2.read();
    if (t1.sec+t2.sec>=60)
    {
        t3.sec=60-(t1.sec+t2.sec);
        t1.min=t1.min+1;
    }
    else
    {
        t3.sec=t1.sec+t2.sec;
    }
    if (t1.min+t2.min>=60)
    {
        t3.min=60-(t1.min+t2.min);
        t1.hours=t1.hours+1;
    }
    else 
    {
        t3.min=t1.min+t2.min;
    }
    t3.hours=t1.hours+t2.hours;
    printf ("%02d %02d %02d", t3.hours, t3.min, t3.sec);
    return 0;
}