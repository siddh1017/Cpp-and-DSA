#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int flip(int n)
{
    int f = 0;
    while (n != 0)
    {
        f = (f*10) + (f%10);
        n = n/10;
    }
    return f;
}


int main()
{
    ifstream in;
    string file, s1, s2;
    cin >> file;
    
    in.open(file);
    while (in.eof()==0)
    {
        in >> s1;
        in >> s2;
        int n1 = stoi(s1), n2=stoi(s2);
        
        int sum1=0, sum2=0;
        for (int i=0 ; i<n1; i++)
        {
            if (n1%i == 0)
            {
                sum1 = sum1 + i;
            }
        }
        for (int i=0 ; i<n2; i++)
        {
            if (n2%i == 0)
            {
                sum2 = sum2 + i;
            }
        }
        int sum_odd=0, sum_even=0;
        if (sum1 == n2 && sum2 == n1)
        {
            int o=1;
            int x=flip(n1);
            while (x != 0)
            {
                if (o%2 != 0)
                {
                    sum_odd = sum_odd + x%10;
                }
                o++;
            }
            int secret_code = x+32;
            cout << n1 << " " << n2 << " " << secret_code;
        }
        else 
        {
            int y=flip(n2);
            int e=1;
            while (y != 0)
            {
                if (e%2 == 0)
                {
                    sum_even = sum_even + y%10;
                }
                e++;
            }
            int secret_code = y+16;
            cout << n1 << " " << n2 << " " << secret_code;
        }
    }
}