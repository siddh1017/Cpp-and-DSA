#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;
};

void traverse_back(node *head)
{
    node* ptr  = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    // now head is pointing last block

    do
    {
        cout << ptr->data << " ";
        ptr = ptr->prev;  // pointing the head to 2nd last ele.
    } while (ptr != head); // itreating it till it reaches 1st ele.
    cout << ptr->data;     // as while loop will end for 1st ele.
    cout << endl;
}

void traverse_front(node *head)
{
    node *ptr=head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    node *block = new node;
    block = (node *)malloc(n * sizeof(node));

    // input for doubly L.L
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cin >> (block + i)->data;
            (block + i)->prev = NULL;
            (block + i)->next = (block + i + 1);
        }
        else if (i == n - 1)
        {
            cin >> (block + i)->data;
            (block + i)->prev = (block + i - 1);
            (block + i)->next = NULL;
        }
        else
        {
            cin >> (block + i)->data;
            (block + i)->prev = (block + i - 1);
            (block + i)->next = (block + i + 1);
        }
    }
    // traverse_back(block); 
    traverse_front(block);
    traverse_back(block);

    return 0;
}