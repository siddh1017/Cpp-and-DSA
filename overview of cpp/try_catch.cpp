#include <iostream>
using namespace std;

class product
{
    public:
    int static id;
    int price ;
    int item;

    product()
    {
        cin >> price >> item;
    }
};

int main()
{
    int n;
    cin >> n;
    product p[n];

    int code,cost;

    try
    {
        cin >> code >> cost;
        for (int i=0 ; i<n; i++)
        {
            if (code == p[i].item)
            {
                if (cost >= p[i].price)
                {
                    cout << p[i].id;
                }
                else
                {
                    throw 0.0;
                }
            }
        } 
    }
    catch(double)
    {
        cout << "Insufficient amout";
    }

    
    return 0;
}