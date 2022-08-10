#include <iostream>
using namespace std;

class line
{
    public:
    int x1, y1, x2, y2;
    line()
    {
        cin >> x1 >> y1 >> x2 >> y2;
    }
    friend int find_horizontal(int , int, line l[], int);
};

int find_horizontal (int a, int b, line l[], int n)
{
    int count=0;
    for  (int i=0; i<n ; i++)
    {
        if (l[i].y1==l[i].y2)
        {
            if (l[i].y1==a || l[i].y1==b)
            {
                count = count + 1;
            }
        }
    }
    if (count == 2)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

int main()
{
    int n;
    cin >> n;
    line l[n];
    int no_of_lines = 0;
    
    for (int i=0 ; i < n ; i++)
    {
        if (l[i].x1==l[i].x2)
        {
            no_of_lines = no_of_lines + find_horizontal(l[i].y1, l[i].y2, l, n);
        }
    }
    cout << no_of_lines;
    return 0;
}