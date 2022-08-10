#include <iostream>
using namespace std;

class single_l
{
    public:
        single_l* next;
        int data;
};

class double_l
{
    public:
        double_l* next;
        double_l* prev;
        int data;
};

void rearrange(double_l * head)
{
    double_l* temp;
    double_l* ptr;

    single_l* head2;
    
}
int main()
{
    int n; 
    cout << "Enter thr no.: ";
    cin >> n;

    double_l *head;
    head = (double_l *)malloc(n * sizeof(double_l));

    // input for doubly L.L
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            cin >> (head + i)->data;
            (head + i)->prev = NULL;
            (head + i)->next = (head + i + 1);
        }
        else if (i == n - 1)
        {
            cin >> (head + i)->data;
            (head + i)->prev = (head + i - 1);
            (head + i)->next = NULL;
        }
        else
        {
            cin >> (head + i)->data;
            (head + i)->prev = (head + i - 1);
            (head + i)->next = (head + i + 1);
        }
    }

    

    return 0;
}