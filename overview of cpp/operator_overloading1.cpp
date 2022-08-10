#include <iostream>
#include <istream>
using namespace std;

class Transmission
{
    int n;
    int m[10][10];

public:
    Transmission(int x)
    {
        n = x;
    }
    void friend operator>>(istream &in, Transmission &T)
    {
        for (int i = 0; i < T.n; i++)
        {
            for (int j = 0; j < T.n; j++)
            {
                in >> T.m[i][j];
            }
        }
    }
    friend int operator>(Transmission &T1, Transmission &T2)
    {
        int count = 0;
        for (int i = 0; i < T1.n; i++)
        {
            for (int j = 0; (j > i && j < T1.n); j++)
            {
                cout << "T1 = " << T1.m[i][j] << " " << "T2 = " << T2.m[i][j] << endl;
                if (T1.m[i][j] > T2.m[i][j])
                {
                    count = count + 1;
                }
            }
        }
        cout << "count = " << count << endl;
        if (count == ((T1.n * T1.n) - T1.n) / 2)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    int n;
    cin >> n;
    Transmission Y1(n), Y2(n);
    cin >> Y1;
    cin >> Y2;
    if (Y1 > Y2)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}