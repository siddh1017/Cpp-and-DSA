#include <ostream>
#include <istream>
#include <iostream>
using namespace std;

class point
{
    int x, y, z;

public:
    friend void operator>>(istream &in, point &p);
    friend void operator<<(ostream &out, point &p);
};

void operator<<(ostream &out, point &p)
{
    out << "+" << p.x << "-" << p.y << "-" << p.z << endl;
}

void operator>>(istream &in, point &p)
{
    char *c1, *c2, *c3;
    in >> c1 >> p.x >> c2 >> p.y >> c3 >> p.z;
    if (c1 == "+" && c2 == "-" && c3 == "-")
    {
        cout << p;
    }
    else
    {
        cout << "Enter Valid Number" << endl;
    }
}

int main()
{
    point p;
    cout << "Enter the number : ";
    cin >> p;
    return 0;
}
