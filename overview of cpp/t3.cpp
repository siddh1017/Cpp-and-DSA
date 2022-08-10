#include <iostream>
#include <string>
using namespace std;
class mobile
{
    int IMEI;
    string model, color;

protected:
    string make;
    float price;

public:
    mobile(int im, string a, string b, string c)
    {
        IMEI = im;
        make = a;
        model = b;
        color = c;
    }
    void setPrice()
    {
        cin >> price;
        if (make == "Samsung")
            price = price - price * 0.05;
    }
    float getprice() { return price; }
};

class smartphone : public mobile
{
    int camera;

public:
    smartphone(int im, string a, string b, string c, int cam) : mobile(im, a, b, c)
    {
        camera = cam;
    }
    void setCamera() { cin >> camera; }
    float getcamera() { return camera; }
    void updatePrice()
    {
        setPrice();
        if (make == "Samsung")
            price = price - price * 0.05;
    }
};
int main()
{
    smartphone s1(1, "Samsung", "11", "black", 21), s2(2, "NOkia", "22", "blue", 18);
    s1.setPrice();
    s1.setCamera();
    s2.updatePrice();
    s2.setCamera();
    if (s1.getprice() < s2.getprice() && s1.getcamera() > s2.getcamera())
        cout << "A";
    else if (s2.getprice() < s1.getprice() && s2.getcamera() > s1.getcamera())
        cout << "B";
    else
        cout << "None";
    return 0;
}