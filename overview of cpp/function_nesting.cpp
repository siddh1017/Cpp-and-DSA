#include <iostream>
#include <string>
using namespace std;

class binary 
{
    string s;
    int chk_binary();
    public:
        void read();
        string ones();
};

void binary :: read()
{
    cout<<"Enter the binary no. ";
    cin>>s;
}

int binary :: chk_binary()
{
    int count = 0;
    for (int i=0 ; i<s.length() ; i++)
    {
        if (s.at(i)!='0' && s.at(i)!='1')
        {
            cout<<"Incorrect binary format";
            count++;
            break;
        }
    }
    if (count == 0)
    {
        return 0;   
    }
}

string binary :: ones()
{
    if (chk_binary()==0)
    {
        for (int i=0; i<s.length() ; i++)
        {
            if (s.at(i)=='1')
            {
                s.at(i)='0';
            }
            else if (s.at(i)=='0')
            {
                s.at(i)='1';
            }
        }
        return s;
    }
}

int main()
{
    binary b;
    b.read();
    cout<<b.ones();
    return 0;
}