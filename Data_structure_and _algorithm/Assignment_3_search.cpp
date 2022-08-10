#include <iostream>
using namespace std;

class list
{
public:
    list *next;
    list *prev;
    int data;

    list * head;
    list * back;
    
    void enque(int size)
    {
        head = (list *)malloc(size * sizeof(list));
        head = NULL;

        back = (list *)malloc(size * sizeof(list));
        back = NULL;

        for (int i = 0; i < size; i++)
        {
            list *ptr;
            ptr = (list *)malloc(sizeof(list));
            cin >> ptr->data;

            if (head == NULL)
            {
                ptr->next = ptr;
                ptr->prev = ptr;
                head = back = ptr;
            }
            else
            {
                back->next = ptr;
                ptr->next = head;
                head->prev = ptr;
                ptr->prev = back;
                back = ptr;
            }
        }
    }

    void search(int x)
    {
        list *ptr = head;
        while (ptr->next != NULL)
        {
            if (ptr->data == x) 
            {
                if (ptr == head)
                {
                    cout << "element found" << endl;
                    cout << "right: " << ptr->next->data << endl;
                    break;
                }
                else if (ptr == back)
                {
                    cout << "element found" << endl;
                    cout << "left: " << ptr->prev->data << endl;
                    break;
                }
                else
                {
                    cout << "element found" << endl;
                    cout << "right: " << ptr->prev->data << " left: " << ptr->next->data << endl;
                    break;
                }
            }
            else if (ptr == back && ptr->data != x)
            {
                cout << "element not found" << endl;
                break;
            }
            ptr = ptr->next;
        }
    }
};

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    list search_l;
    search_l.enque(n);
    
    int x;
    cout << "element search: ";
    cin >> x;

    search_l.search(x);
    return 0;
}