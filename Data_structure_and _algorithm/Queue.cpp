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
        void enqueue()
        {
            if (is_full())
            {
                cout << "Queue FULL!!" << endl;
            }
            else 
            {
                b=b+1;
                cout << "Enter the element: ";
                cin >> arr[b];
                cout << "Element enqueued" << endl;
            }
        }
        void deque(void)
        {
            if (is_empty())
            {
                cout << "Queue EMPTY!!" << endl;
            }
            else
            {
                f=f+1;
                cout << "Element: " << arr[f] << " dequed" << endl;
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
                for (int i=f+1; i<b+1; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    int size_qu;
    cout << "Enter the size of que: ";
    cin >> size_qu;
    
    que <float> qu(size_qu);
    
    char ch;
    while (ch != 'q')
    {
        cout << "Press:  a.enqueue  b.deque  c.full  d.empty  e.display  q.exit: ";
        cin >> ch;
        switch (ch)
        {
            case 'a':
                qu.enqueue();
                break;
            case 'b':
                qu.deque();
                break;
            case 'c':
                if (qu.is_full())
                    cout << "Queue Full!!" << endl;
                else
                    cout << "Queue NOT Full!!" << endl;
                break;
            case 'd':
                if (qu.is_empty())
                    cout << "Queue Empty!!" << endl;
                else
                    cout << "Queue NOT Empty!!" << endl;
                break;
            case 'e':
                qu.display();
                break;
            default:
                break;
        }
    }
    return 0;
}

