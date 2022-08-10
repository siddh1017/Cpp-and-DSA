#include <iostream>
using namespace std;
 // code works on FIFO principle
class list
{
public:
    list *next;
    list *prev;
    int data;
};

class que
{
public:
    list *front;
    list *rear;
    int size;

    que(int x)
    {
        size = x;
        front = (list *)malloc(size * sizeof(list));
        rear = (list *)malloc(size * sizeof(list));
        front = rear = NULL;
    }

    void enque(int x)
    {
        list *ptr;
        ptr = (list *)malloc(sizeof(list));
        ptr->data = x;

        if (front == NULL)
        {
            ptr->next = ptr;
            ptr->prev = ptr;
            front = rear = ptr;
        }
        else
        {
            rear->next = ptr;
            ptr->next = front;
            front->prev = ptr;
            ptr->prev = rear;
            rear = ptr;
        }
        cout << "element: " << x << " equed" << endl;
    }

    void deque()
    {
        list* ptr = front;
        front = front->next;
        rear->next = front;
        front->prev  = rear;
        
        cout << "element: " << ptr->data << " dequed" << endl;
        free (ptr);
    }

    bool search (int x)
    {
        list* ptr = front;
        while (ptr != NULL)
        { 
            if (ptr->data == x)
                return true;
            else if (ptr == NULL && ptr->data != x)
                return false;
            ptr = ptr->next;
        }
    }

    void reverse_display()
    {
        list* ptr = rear;
        while (ptr->prev != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->prev;
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "size of que: ";
    cin >> n;

    que q(n);
    q.enque(21);
    q.enque(12);
    q.enque(44);
    q.enque(54);

    // q.reverse_display();
    
    q.deque();
    q.deque();

    q.reverse_display();

    return 0;
}