#include <iostream>
using namespace std;

class vector
{
int n;
int v[100];
public:
//vector(){v}
void set();
void print();
vector add(vector &v1, vector &v2); //v1+v2
vector operator+(vector v2);
vector operator*(int);
// vector operator++(); //A++ 222 333 444
};

void vector::set()
{
    cout << "enter the no. of elements needed in a vector ";
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>v[i];
    }
}

void vector::print()
{
    for (int i=0; i<n; i++)
    {
        cout<<v[i]<<" ";
    }
}

vector vector::operator+(vector v2)
{
    vector sum;
    sum.n=n;
    
    for (int i=0; i<sum.n; i++)
    {
        sum.v[i]=this->v[i]+v2.v[i];
    }
    return sum;
}

vector vector::operator*(int x)
{
    vector mult;
    mult.n=n;
    for (int i=0; i<mult.n; i++)
    {
        mult.v[i]=this->v[i]*x;
    }
    return mult;
}

// vector vector::operator++()
// {
//     for (int i=0; i<n; i++)
//     {
//         v[i]=v[i]+1;
//     }
//     return v;
// }

int main()
{
    vector A,B,C,D;
    A.set();
    B.set();
    C=A+B; //operator overloading
    cout << "The sum is ";
    C.print();
    cout<<endl;
    D=A*2;
    cout << "The multipication value is ";
    D.print();
    // cout<<endl;
    // ++A;
    // A.print();
    return 0;
}
