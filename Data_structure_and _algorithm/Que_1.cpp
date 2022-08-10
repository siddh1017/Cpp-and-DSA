#include <iostream>
using namespace std;

class list
{
public:
    list *next;
    int data;
};

class stack
{
public:
    int top = -1, arr[100], size;
    stack() {}
    stack(int n)
    {
        size = n;
        int arr[n];
    }

    void push(int x)
    {
        top = top + 1;
        arr[top] = x;
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "The elements in stack are in order: ";
            cout << arr[i] << " ";
        }
    }
};

class que
{
public:
    list *front;
    list *rear;
    stack st;

    que(int s)
    {
        stack st(s);
        front = rear = NULL;
        front = (list *)malloc(s * sizeof(list));
        rear = (list *)malloc(s * sizeof(list));
    }

    void enque(int n)
    {
        for (int i = 0; i < n; i++)
        {
            list *n;
            cin >> n->data;

            if (front == NULL)
            {
                front = rear = n;
            }
            else
            {
                rear->next = n;
                rear = n;
                n->next = NULL;
            }
        }
    }

    int deque(int size) // need to edited
    {
        list *ptr = front;
        while (ptr != NULL) // it could also iterated till ptr->next = rear
        {
            if ((ptr->data % 2) != 0)
            {
                if (ptr == front)
                {
                    list *temp = front;
                    front = temp->next;
                    ptr = temp->next;
                    free(temp);
                    st.push(front->data);
                }
                else if (ptr == rear)
                {
                    list *temp = front;
                    while (temp->next != rear)
                    {
                        temp = temp->next;
                    }
                    temp->next = ptr->next;
                    rear = temp;
                    free(temp);
                    free(ptr);
                    st.push(rear->data);
                }
                else
                {
                    list *temp = front;
                    while (temp->next != ptr)
                    {
                        temp = temp->next;
                    }
                    temp->next = ptr->next;
                    temp = ptr;
                    ptr = ptr->next;
                    free(temp);
                    st.push(ptr->data);
                }
            }
        }
        while (front != rear)
        {
            list* temp;
            while (temp->next != rear)
            {
                temp = temp->next;
            }
            temp->next = rear->next;
            rear = temp;
            temp = temp->next;
            free (temp);
            st.push(rear->data);
        }
    }
};

int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;

    que q(n);

    return 0;
}