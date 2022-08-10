#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

void print_list(node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

node *insertAtFrirst(node *head, int data)
{
    node *ptr = new node;
    ptr = (node *)malloc(sizeof(node));

    ptr->data = data;
    ptr->next = head;
    return ptr;
}

node *insertAtindex(int data, int index, node *b)
{
    node *ptr = new node;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = data;

    node *p = b;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return b;
}

node *insert_at_end(int data, node *b)
{
    node *ptr = new node;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = data;

    node *p = b;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return b;
}

node *insert_after_node(node *pre_block, int data, node *block)
{
    node *ptr = new node;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = data;

    ptr->next = pre_block->next;
    pre_block->next = ptr;
    return block;
}

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

    print_list(block);

    // INSERT AT FIRST------------------>
    int new_ele;
    cout << "Enter the new element: ";
    cin >> new_ele;
    
    block = insertAtFrirst(block, new_ele); //block pointing the first element (HEAD)
    print_list(block);

    // insert at INDEX ---------------------->
    //taking an input at what index one want to insert
    int index;
    cout << "ENter index after which ele. inserted: ";
    cin >> index;

    block = insertAtindex(23, index, block);
    print_list(block);

    // INsert at END-------------------------------->
    // here we take the element and point its node as NULL
    // and point actual end block starts to new block

    int end_value;
    cout << "ENter the value of end ele.: ";
    cin >> end_value;

    block = insert_at_end(end_value, block);
    print_list(block);

    // insert after the given NODE---------------------------->
    // In this NODE is given not an INDEX
    // so there is no need to surf through complete block
    int x;
    cout << "ENter the node after which u need to insert ele.: ";
    cin >> x;

    block = insert_after_node((block + x), 44, block);
    print_list(block);

    
    return 0;
}