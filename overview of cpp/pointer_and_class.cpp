#include <iostream>
using namespace std;

class complex
{
private:
    float real, img;

public:
    void write (void)
    {
        cout << "The real part is " << real << endl;
        cout << "The imaginary part is " << img << endl;
    }
    void set(void)    
    {
        cin >> real;
        cin >> img;
    }
};

int main()
{
    complex c1;
    complex *ptr = &c1;
    (*ptr).set();
    (*ptr).write();

    // second way 
    complex *pty = new complex; // the difference
    pty->set(); //as same as (*pty).set(); 
    pty->write(); // as same as (*pty).write();

    complex *pr = new complex[3];
    for (int i=0 ; i<3; i++)
    {
        (pr+i)->set();
    }
    for (int i=0 ; i<3; i++)
    {
        (pr+i)->write();
    }

    return 0;
}