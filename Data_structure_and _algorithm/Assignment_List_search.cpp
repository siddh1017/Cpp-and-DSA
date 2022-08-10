// in below program the merge sort is performed on list
// and then binary search is performed to find data

#include <iostream>
using namespace std;

class node  // list strurct
{
    public:
        int data;
        node* next;
};

void mid (node * cur, node** first, node** second)  // function used to find middle element
{
    node * slow ;
    node * fast ;
    slow = cur;
    fast  = cur->next;

    while (fast != NULL)  // slow will be the middle ele. after iterating
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *first = cur;
    *second = slow->next;
    slow->next = NULL;  // breaking the list from middle
}

node* merge (node* first , node*second)  // merging the sub-list
{
    node* ans = NULL;

    if (!first)  // base condition
        return second;
    else if (!second)
        return first;

    if (first->data <= second->data)
    {
        ans = first;
        ans->next = merge (first->next, second);
    }
    else
    {
        ans = second;
        ans->next = merge (first, second->next);
    }
    return ans;
}

void mergesort (node** head)  // merge sort 
{
    node * cur = *head;
    node* first; node * second;
    
    if (!cur || !cur->next)  // if there is only one ele.
        return;
    
    mid (cur, &first, &second);

    mergesort(&first);
    mergesort(&second);
    * head = merge (first, second); 
}

node* mid_search (node * front , node* rear)  // function to find the mid element for binary serach 
{
    node *slow = front;
    node * fast = front->next;

    while (fast != rear)
    {
        fast = fast->next;
        if (fast != rear)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;  // slow = middle ele.
}

void binary_search (node* head, int value)
{
    node* front = head;
    node* temp = head;
    node* rear;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    rear = temp;
    free (temp);
    
    while (front->data <= rear->data)
    {
        node * mid = mid_search(front, rear);
        if (mid->data = value)
        {
            cout << "data found";
            break;
        }
        if (value > mid->data)
        {
            front = mid->next;  
        }
        if (value < mid->data)
        {
            rear = mid;
        }
        if (front == rear || value != mid->data)
        {
            cout << "No such data";
            break;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of linked list: ";
    cin >> n;

    node *block = new node;
    block = (node *)malloc(n* sizeof(node));

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

    mergesort(&block);

    int search ;
    cout << "Elemnet to be searched: ";
    cin >> search;
    binary_search (block , search);
     
    return 0;
}