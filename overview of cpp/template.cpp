#include <iostream>
using namespace std;

template <class T> // defining the template, where T can be any varaible type (int, float ,char , etc,.)

class vector
{
    private:
        int size;
    public:
        T* arr;
        vector (int s)
        {
            size = s;
            arr = new T[size];
        }
        T dotProduct (vector &v)
        {
            T count = 0;
            for (int i=0; i<size; i++)
            {
                count = count + (this->arr[i]*v.arr[i]);
            }
            return count;
        }
};

int main()
{
    vector <float> v1(3); // creating a class which says T must be float type 
    v1.arr[0] = 1.2;
    v1.arr[1] = 1.1;
    v1.arr[2] = 1.2;

    vector <float> v2(3);
    v2.arr[0] = 1.5;
    v2.arr[1] = 1.6;
    v2.arr[2] = 0.2;

    float ans = v1.dotProduct(v2);
    cout  << ans;
    return 0;
}