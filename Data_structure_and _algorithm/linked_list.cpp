#include <iostream>
using namespace std;

class node
{
    public:
        int data;
        node* next;

};
void print_list(node * ptr)
{
    while (ptr!=NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr ->next;
    }
}


int main()
{
    node* head = new node;
    node* second = new node;
    node* third = new node;

    head->data = 10;
    head->next = second;
    
    second->data = 32;
    second->next = third;
    
    third->data = 45;
    third->next = NULL;

    print_list(head);

    
    return 0;
}