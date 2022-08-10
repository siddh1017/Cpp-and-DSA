#include <iostream>

using namespace std;

// class employee
// {
//     int id;
//     int salary;
//     public:
//     void setId()
//     {
//         cout << "Enter the id of employee";
//         cin>>id;
//     }
//     void getId()
//     {
//         cout<<"The id of the employuee is "<<id<<endl;
//     }
// };


// int main()
// {
//     employee fb[4];
//     for (int i=0 ; i<4; i++)
//     {  
//         fb[i].setId();
//         fb[i].getId();
//     }

//     return 0;
// }

class complex
{
    int real, img;
    public:
    void set()
    {
        cout << "Enter the real part ";
        cin >> real;

        cout << "Enter the imgnary part ";
        cin >> img;
    }
    void setDataBySum(complex o1, complex o2)
    {
        real = o1.real + o2.real;
        img = o1.img + o2.img;

    }
    void printData()
    {
        cout << "complex no. is "<< real<< " + i"<< img << endl;
    }
};

int main()
{
    complex c1,c2,c3;

    c1.set();
    c2.set();
    c3.setDataBySum(c1,c2);
    c3.printData();
}