#include <iostream>
using namespace std;

template <class T>
class P_queue
{
    private:
        int priority[100], size;
        T ele[100];
        int f=-1, r=-1;
    public:
        P_queue(int s)
        {
            size=s;
            int priority[size];
            T ele[size];
        }
        bool is_full()
        {
            if (r==size-1)
                return true;
            else 
                return false;
        }
        bool is_empty()
        {
            if (f==r)
                return true;
            else 
                return false;
        }
        void enqueue (void)
        {
            if (is_full())
            {
                cout << "Queue FULL!!" << endl;
            }
            else
            {
                r=r+1;
                cout << "Enter the element: ";
                cin >>ele[r];
                cout << "Enter the priority: ";
                cin >> priority[r];
            }
        }
        void dequeue(void)
        {
            if (is_empty())
            {
                cout << "Queue Empty!!" << endl;
            }
            else
            {
                int pos = check_priority();
                for (int i=f+1; i<pos; i++)
                {
                    ele[pos-i]=ele[pos-i-1];
                    priority[pos-i] = priority[pos-i-1];
                }
                f=f+1;
            }
        }
        int check_priority(void)
        {
            int max = priority[f+1], index=f+2;
            for (int i=f+2; i<r+1; i++)
            {
                if (priority[i] > max)
                {
                    max = priority[i];
                    index = i;
                }
            }
            return index;
        }
        void display(void)
        {
            if (is_empty())
            {
                cout << "Queue EMPTY!!" << endl;
            }
            else
            {
                for (int i=f+1; i<r+1; i++)
                {
                    cout << ele[i] << " ";
                }
                cout << endl;
            }
        }
};

int main()
{
    int size_que;
    cout << "Enter the size of queue: ";
    cin >> size_que;
    
    P_queue <int> pque(size_que);
    
    char ch;
    while (ch != 'q')
    {
        cout << "Press:  a.enqueue  b.deque  c.full  d.empty  e.display  q.exit: ";
        cin >> ch;

        switch (ch)
        {
            case 'a':
                pque.enqueue();
                break;
            case 'b':
                pque.dequeue();
                break;
            case 'c':
                if (pque.is_full())
                    cout << "Queue Full!!" << endl;
                else
                    cout << "Queue NOT Full!!" << endl;
                break;
            case 'd':
                if (pque.is_empty())
                    cout << "Queue Empty!!" << endl;
                else
                    cout << "Queue NOT Empty!!" << endl;
                break;
            case 'e':
                pque.display();
                break;
            default:
                break;
        }
    } 
    return 0;
}