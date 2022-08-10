#include <iostream>
using namespace std;

/*
5
* * * * *
* 2 2 2 *
* 3 3 3 *
* 4 4 4 *
* * * * *
*/

/*
5 6
* * * * * *
* 2 2 2 2 *
* 3 3 3 3 *
* 4 4 4 4 *
* * * * * *
*/

void sqrec(int s)
{
    for (int i=0; i<s; i++)
    {
        for (int j=0; j<s; j++)
        {
            if (i==0 || i==(s-1) || j==0 || j==(s-1))
            {
                cout<<"* ";
            }
            else 
            {
                cout<<i+1<<" ";
            }
        }
        cout<<"\n";
    }
}

void sqrec(int l, int b)
{
    for (int i=0; i<l; i++)
    {
        for (int j=0; j<b; j++)
        {
            if (i==0 || i==(l-1) || j==0 || j==(b-1))
            {
                cout<<"* ";
            }
            else 
            {
                cout<<i+1<<" ";
            }
        }
        cout<<"\n";
    }
}

int main()
{
    int s,l,b;
    cin>>s>>l>>b;
    sqrec(s);
    sqrec(l,b);
    return 0;
}