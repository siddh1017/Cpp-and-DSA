#include <iostream>
using namespace std;

class matrix
{
    int rows, coloums;
    int a[100][100];

public:
    void setdata(int x, int y)
    {
        rows = x;
        coloums = y;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                cin >> a[i][j];
            }
        }
    }
    void operator++(void)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < coloums; j++)
            {
                a[i][j] = a[i][j] + 1;
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int m, n;
    cin >> m >> n;
    matrix mat;
    mat.setdata(m, n);
    ++mat;
    return 0;
}