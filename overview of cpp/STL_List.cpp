#include <iostream>
#include <list>
using namespace std;

template <class T>
void get(list<T>& l)
{
    int size;
    cout << "Enter The size of list: ";
    cin >> size;
    T ele;
    cout << "Enter the elements: ";
    for (int i=0; i<size; i++)
    {
        cin >> ele;
        l.push_back(ele);
    }
    // list<T> :: (std::iterator) itr;
    // for (itr = l.begin(); itr != l.end(); itr++)
    // {
    //     cin >> *iter;
    // }
} 

void display (list<int>& l)
{   
    list<int> :: iterator itr;
    cout << "The elements are: ";
    for (itr = l.begin(); itr != l.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endl;
}

int main()
{
    list <int> l1;
    get(l1);
    display(l1);

    list <char> l2;
    get(l2);

    l1.sort(); // sort the list int ascending order
    display(l1);

    l1.reverse(); // will reverse the list
    display(l1);

    l1.pop_back(); // removes the last element 
    display(l1);

    l1.pop_front(); // removes the first element 
    display(l1);

    // l1.remove(ele); // removes the particular element from list

    list <int> l3;
    get(l3);
    display(l3);

    cout << "After merging list1 and list2, list1 ";
    l1.merge(l3);
    display(l1);
    return 0;
}