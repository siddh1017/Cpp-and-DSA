#include <iostream>
using namespace std;

class node 
{
    public:
        int data;
        node* next;
};

int main()
{
    int n;
    cout << "Enter the size of linked list: ";
    cin >> n;

    node *block = new node;
    block = (node *)malloc(sizeof(node));

    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cin >> (block + i)->data;
            (block + i)->next = NULL;
        }
        else
        {
            cin >> (block + i)->data;
            (block + i)->next = (block + i + 1);
        }
    }

    
    return 0;
}