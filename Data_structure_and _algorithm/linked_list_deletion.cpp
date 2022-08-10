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

node *delete_at_first(node *head) // Delete at FIRST position--------------------->
{
    node *ptr = head; // creating the one more node* which points at head
    head = ptr->next; // asking head to point next element in list
    free(ptr);        // freeing the ptr after use do no memory is left waste
    return head;
}

node *delete_at_index(node *head, int index) // delete at Ith position given by user -------------------->
{
    node *ptr = head; // creating the one more node* which points at head
    int i = 0;
    while (i != index - 1) // itreating the ptr though list tull we reaches just previous index
    {
        ptr = ptr->next;
        i++;
    }
    node *temp = ptr->next; // creating the one more node* which points at ptr
    ptr->next = temp->next; // asking ptr to point next element in list
    free(temp);             // freeing the block
    return head;
}

node *delete_at_end(node *head) //delete at END ---------------------------->
{
    node *ptr = head;           // creating the one more node* which points at head  
    node *temp = head->next;    // creating the one more node* which points block after node
    while (temp->next != NULL)  // itreating till temp points last ele. and ptr 2nd last
    {
        ptr = ptr->next;
        temp = temp->next;
    }
    ptr->next = temp->next;  //making ptr->next NULL (last ele.)
    free(temp);              // freeing the block 
    return head;
}

node* delete_element(node* head, int data) //delete PARTICULAR element from the list
{
    node *ptr = head;           // creating the one more node* which points at head  
    node *temp = head->next;    // creating the one more node* which points block after node
    while (temp->data!=data && temp->next!=NULL)  // itreating till temp points last ele. and ptr 2nd last
    {
        ptr = ptr->next;
        temp = temp->next;
    }
    if (temp->data == data) // chacking whether while ended with 1st condition or not
    {
        ptr->next = temp->next;
        free(temp);
    }
    return head;
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
            (block + i)->next = NULL;
        }
        else
        {
            cin >> (block + i)->data;
            (block + i)->next = (block + i + 1);
        }
    }
    print_list(block);

    block = delete_at_first(block); // delete at FIRST
    print_list(block);

    block = delete_at_index(block, 2); // delete at INDEX
    print_list(block);

    block = delete_at_end(block); // delete at END
    print_list(block);

    block = delete_element(block, 3); // delete at END
    print_list(block);
    return 0;
}