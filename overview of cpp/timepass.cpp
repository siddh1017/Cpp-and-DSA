#include <iostream>
#include <stdio.h>
using namespace std;

class item
{
    float price;
    string name;
    
    public:
    
    string returnName()
    {
        return name;
    }
    float returnPrice()
    {
        return price;
    }
    item()
    {
        cin>>name>>price;
    }
};


int main()
{
    int n;
    cin>>n;
    item a[n];
    
    int m;
    cin>>m;
    
    float total_price=0;
    string order[m];
    int quantity[m];
    
    for (int i=0; i<m; i++)
    {
        cin>>order[i]>>quantity[i];
    }
    
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (a[j].returnName()==order[i])
            {
                total_price=total_price+(a[j].returnPrice()*quantity[i]);
            }
        }
    }
    
    printf("%.2f ", total_price);
    
    float discount;
    if (total_price<=3000)
    {
        discount=total_price*0.02;
    }
    else if (total_price>3000 && total_price<=6000)
    {
        discount=total_price*0.05;
    }
    else if (total_price>6000)
    {
        discount=total_price*0.10;
    }
    printf ("%f", discount);
    
    float net_price=total_price-discount;
    printf ("%f", net_price);
    
    return 0;
}