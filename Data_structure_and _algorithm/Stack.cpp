#include <iostream>
using namespace std;

class stack
{
    private:
        int size, top=-1;
        int arr[100];
    public:
        stack(int s)
        {
            size = s;
            int arr[s];
        }
        bool is_full(void)  // function to check for space
        {
            if (top == size-1)
                return true;
            else 
                return false;
        }
        bool is_empty(void)  // fucntion to check whether stck  empty or not
        {
            if (top == -1)
                return true;
            else 
                return false;
        }
        void push(void)  // input fucntion
        {
            if (is_full())
            {
                cout << "Stack Overflow!!" << endl;
            }
            else
            {
                top = top + 1;
                cin >> arr[top];
                cout << "Element pushed" << endl;
            }
        }
        int pop(void)  // delete elemnet fucntion 
        {
            if (is_empty())
            {
                cout << "Stack Underflow!!" << endl;
            }
            else
            {
                top = top - 1;
            }
            return arr[top + 1];
        }
        void display(void)  // display  function in stack 
        {
            if (is_empty())
            {
                cout << "Stack EMPTY!!" << endl;
            }
            else
            {
                for (int i=0; i<top+1; i++)
                {
                    cout << arr[i] << " ";
                }
                cout << endl;
            }
        }
};
class circular_que
{
    private:
        int f, b=-1, size;
        int arr[1000];

    public:
        circular_que(int s)   // constructor
        {
            size = s;
            f = s; 
            int arr[size];
        }
        bool is_full()   // function to check for space
        {
            if ((b+1)%size == f)
                return true;
            else 
                return false;
        }
        void enqueue_rear(int x)   // passing the stack top
        {
            if (is_full())   // checking whether the queue is full or not
            {
                cout << "Queue FULL!!" << endl;
            }
            else 
            {
                arr[b] = x;
                cout << "Element " << x  << " enqueued" << endl;
                b=(b+1)%size;
            }
        }

        void enqueue_front(int y)  // passing the stack top
        {
            if (is_full())  // checking whether the queue is full or not
            {
                cout << "Queue FULL!!" << endl;
            }
            else 
            {
                f = f -1;
                arr[f] = y;
                cout << "Element " << y << " enqueued" << endl;
            }
        } 
        void display(void)   // displaing the elements index wise 
        {
            for (int i=0; i<size ; i++)
            {
                cout << arr[i] << " ";
            }
        }
};

int main()
{
    int st_size;
    cout << "Enter the size of stack: ";
    cin >> st_size;
    
    stack st(st_size); // creating the stack object

    cout << "Enter the elements: ";  // pushing elements in stack
    for (int i=0 ; i < st_size ; i++)
    {
        st.push();
    }   

    cout << "Element In Stack before transffering: ";
    st.display();
    cout << endl;

    circular_que queue (st_size); // creating the circular queue (double eneded queeu) 

    for (int i=0; i<st_size ; i++)  // filling the queue
    {
        int data = st.pop();
        if (i%2 == 0)
            queue.enqueue_rear(data);
        else
            queue.enqueue_front(data);
    }
    cout << endl;

    cout << "Element In Stack after transffering: ";
    st.display();
    cout << endl;

    cout << "Data display in double endened queue: ";
    queue.display();
    cout << endl;


    return 0;
}