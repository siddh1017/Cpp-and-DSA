#include <iostream>
using namespace std;

class compare
{
    int n;
    string s;

public:
    int operator==(compare);
    void operator>>(compare);
    void operator<<(compare);
    void print();
};

void compare ::operator>>(compare obj)
{
    cin >> n >> s;
}

void compare :: print (void)
{
    cout << n << " " << s;
}

// int compare ::operator==(compare obj)
// {
//     // if (this->n==obj.n && this->s==obj.s)
//     // {
//     //     return 1;
//     // }
//     cout << "this->n " << this->n << endl;
//     cout << "n " << n << endl;

// }

void compare ::operator<<(compare obj)
{
    cout << n << " " << s << endl;
}

int main()
{
    compare c, o2, o1;
    o1 >> c;
    o2 >> c;

    // if ((o1 == o2) == 1)
    // {
    //     o1 << c;
    //     o2 << c;
    //     cout << "Both Objects are same bro";
    // }
    // else 
    // {
    //     cout << "Sorry Objects are differet";
    // }

    o1 << c;
    o2 << c;

    return 0;
}