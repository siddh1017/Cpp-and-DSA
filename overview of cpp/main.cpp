#include <iostream>

using namespace std;
class mobile
{
protected:
    int imei;
    string model, color;

public:
    mobile(int a, string b, string c)
    {
        cout << "mobile constructor ";
        //imei=1; model="1100"; color="white";
        imei = a;
        model = b;
        color = c;
    }
    void getdata() { cin >> imei >> model >> color; }
    void printdata() { cout << imei << " " << model << "  " << color << endl; }
};

class smartphone : public mobile // all public of mobile---> public in smartphone
//all protected of mobile --> protected in smartphone
// cant inherit private members of mobile
{
    int pixelq;

public:
    smartphone(int a, string b, string c, int d) : mobile(a, b, c)
    {
        cout << "smartphone constructor ";
        //pixelq=12;
        pixelq = d;
    }
    void getdatasmart()
    {
        //getdata();
        cin >> imei >> model >> color;
        cin >> pixelq;
    }
    void printpixel() { cout << pixelq << endl; }
};

int main()
{
    mobile m1(11, "nokia", "black");
    cout << endl;
    //m1.getdata();
    m1.printdata();
    smartphone s1(1200, "samsung j9", "white", 14);
    //s1.getdatasmart();
    s1.printdata();
    s1.printpixel();

    smartphone s2(120440, "samsung j7", "black", 11);
    //s1.getdatasmart();
    s2.printdata();
    s2.printpixel();

    return 0;
}
