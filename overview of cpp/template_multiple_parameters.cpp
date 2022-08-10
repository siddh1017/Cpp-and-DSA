#include <iostream>
using namespace std;

template <class T1 = int , class T2 = float> // defining the template with deafault parameters 

class Data
{
    private:
        T1 data1;
        T2 data2;
    public:
        Data (T1 a, T2 b)
        {
            data1 = a;
            data2 = b;
        }
        void display (void);
};
template <class T1  , class T2>
void Data <T1, T2> :: display ()
{
    cout << this->data1 << " " << this->data2 << endl; 
} 

int main()
{
    Data <> d1(4, 4.4);
    d1.display();

    Data <string , float> d("Siddh", 34.56);
    d.display();

    return 0;
}