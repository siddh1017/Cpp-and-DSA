#include <iostream>
using namespace std;

int main()
{
    int n = 12345;
    int sum = 0;
    // n = n % 1000;
    // int m=n/100;

    // cout << m;

    int a, b;
    for (int i = 1; i <= 5; i++)
    {
        a = n % (10 * i);
        b = n / (10 * (i - 1));
        
    }
    cout << sum;
    return 0;
}