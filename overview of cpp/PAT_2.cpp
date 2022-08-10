#include <iostream>
using namespace std;

int static count = 1;

class phone
{

    string name;
    int number;
    string city;

public:
    phone()
    {
        cin >> name >> number >> city;
        count++;
    }
    void option1();                         // display function
    friend void option2(string, phone p[]); // search_by_name
    friend void option3(int, phone p[]);    // search_by_number
};

void phone ::option1()
{
    cout << name << " " << number << " " << city << endl;
}

void option2(string s, phone p[])
{
    for (int i = 0; i < count; i++)
    {
        if (s == p[i].name)
        {
            cout << p[i].number << endl;
        }
    }
}

void option3(int m, phone p[])
{
    for (int i = 0; i < count; i++)
    {
        if (m == p[i].number)
        {
            cout << p[i].name << endl;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    phone p[n];

    int user;
    while (user != 4)
    {
        cin >> user;
        if (user == 1)
        {
            for (int i = 0; i < n; i++)
            {
                cout << i + 1 << " ";
                p[i].option1();
            }
        }
        else if (user == 2)
        {
            string sname;
            cin >> sname;
            option2(sname, p);
        }
        else if (user == 3)
        {
            int pnum;
            cin >> pnum;
            option3(pnum, p);
        }
    }
}
