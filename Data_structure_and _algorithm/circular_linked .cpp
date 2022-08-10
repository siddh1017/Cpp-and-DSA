#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void print_list(node *head)
{
    node *ptr =head;
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }while (ptr != head);
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of linked list: ";
    cin >> n;

    node *block = new node;
    block = (node *)malloc(n * sizeof(node));

     for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cin >> (block + i)->data;
            (block + i)->next = block;
        }
        else
        {
            cin >> (block + i)->data;
            (block + i)->next = (block + i + 1);
        }
    }
    return 0;
}