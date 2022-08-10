#include <iostream>
using namespace std;

template <class T>
class que
{
    private:
        int f=-1, b=-1, size;
        T arr[1000];
    public:
        que(int s)
        {
            size = s;
            int arr[size];
        }
        bool is_full()
        {
            if (b==size-1)
                return true;
            else 
                return false;
        }
        bool is_empty()
        {
            if (f==b)
                return true;
            else 
                return false;
        }
        void enqueue(int x)
        {
            if (is_full())
            {
                cout << "Queue FULL!!" << endl;
            }
            else
            {
                b=b+1;
                arr[b]=x;
            }
        }
        void enqueue_rear(int y)
        {
            b=(b+1)%size;
            arr[b]=y;
        }
        int deque(void)
        {
            if (is_empty())
            {
                cout << "Queue EMPTY!!" << endl;
            }
            else
            {
                f=f+1;
                return arr[f];
            }
        }
        void display(void)
        {
            if (is_empty())
            {
                cout << "Queue EMPTY" << endl;
            }
            else
            {
                int i=0;
                while (i!=b+1)
                {
                    cout << arr[i] << " ";
                    i++;
                }
                cout << endl;
            }
        }
        
};

bool prime(int n)
{
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int size_qu;
    cout << "Enter the size of que: ";
    cin >> size_qu;
    
    que <int> qu(size_qu);
    que <int> qu_A(size_qu);
    que <int> qu_B(size_qu);
    que <int> qu_C(size_qu);
    
    int age;
    cin >> age;
    while (age!=-1) // Entering the element in original Queue
    {
        qu.enqueue(age);
        cin >> age;
    }
    
    for (int i=0; i<size_qu; i++)
    {
        int x = qu.deque();
        if ((x%5)==0)
        {
            qu_A.enqueue(x);
        }
        else if ((x%11)==0)
        {
            qu_B.enqueue(x);
        }
        if (prime(x))
        {
            qu_C.enqueue(x);
        }
        else
        {
            qu.enqueue_rear(x);
        }
    }
    
    qu.display();
    qu_A.display();
    qu_B.display();
    qu_C.display();
    
    return 0;
}





