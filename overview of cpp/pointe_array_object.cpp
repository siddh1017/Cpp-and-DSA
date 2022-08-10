#include <iostream>
using namespace std;

class shop
{
private:
    int id;
    float price;

public:
    void setData(void)
    {
        cin >> id >> price;
    }
    void getData(void)
    {
        cout << "Code of the item is " << id  << endl;
        cout << "Price is " << price << endl;
    }
};

int main()
{
    shop *ptr = new shop[3]; // we are creating the container ptr which stores the 3 shop objects 
    for (int i=0; i<3; i++)
    {
        cout << "Enter id and price of shop " << i+1 << endl;
        ptr->setData();
        ptr++;  
    }

    ptr=ptr-3;
    // ptr has reached to point the shop 3 and so to point at shop 1 we do ptr-3
    for (int i=0 ; i<3; i++)
    {
        cout << "shop details of shop no." << i+1 << " ";
        ptr->getData();
        ptr++;
    }
    return 0;
}