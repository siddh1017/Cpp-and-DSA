#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class mobile
{
    long int imei;
    string color;
    string model;
    int price;

    public:
    
    void print()
    {
        cout<<imei<<" "<<color<<" "<<model<<" "<<price<<"\n";
    }
    mobile() //deafault constructor
    {
        imei=11111;
        model="nokia";
        color="black";
        price=1000;
    }
    mobile(long int a, string b, string c, int d)   //parameterized 
    {
        imei=a;
        color=b;
        model=c;
        price=d;
    }
    /*void updatePrice(int e)
    {
        price=e;
    }*/
    mobile(mobile &m2)
    {
        imei=m2.imei;
        color=m2.color;
        model=m2.model;
        price=m2.price;
    }

};

int main()
{
    mobile m1;
    mobile m2(11112,"white","apple",1200);
    //m2.updatePrice(2100);
    m1.print();
    m2.print();

    mobile m3(m2);
    m3.print();

    return 0;
}