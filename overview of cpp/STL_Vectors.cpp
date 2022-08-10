#include <iostream>
#include <vector>
using namespace std;

// v.size --> gives the size of vector v
// v.at --> points at the particular point
// v.push_back(element) --> insert the element in the vector
// v.pop_back() --> will pop the last element

template <class T>
void display(vector<T> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;
}

template <class T>
void input(vector<T> &v)
{
    int size;
    T ele;
    cout << "Enter the size of vector: ";
    cin >> size;
    cout << "Enter the elements: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> ele;
        v.push_back(ele);
    }
}

int main()
{
    vector<int> vec1;
    // int size, ele;
    // cout << "Enter the size of vector ";
    // cin >> size;
    // for (int i = 0; i < size; i++)
    // {
    //     cin >> ele;
    //     vec1.push_back(ele); // add the element int the vector
    // }
    input(vec1);
    display(vec1);

    vec1.pop_back(); // will pop the last element
    display(vec1);

    // iterator
    vector<int>::iterator iter;
    iter = vec1.begin();  // vec1.begin() means that iter will start pointing vector from its 0th position
    vec1.insert(iter, 6); // insert the 6 at the begin
    display(vec1);
    vec1.insert(iter + 1, 10); // insert 10 at 2 position
    display(vec1);
    vec1.insert(iter, 3, 4); // insert the 4 3's in the begin of the vector
    display(vec1);

    // other ways to declare vector
    vector<char> vec2(3); // creates the vector of size 3
    input(vec2);
    display(vec2);

    vector<char> vec3(vec2); // will create the vector of size and elements same as vec2
    display(vec3);

    vector<float> vec4(5.0, 4); // will create the vector which has 4  5.0's
    display(vec4);

    vector<float> vec5(vec4);
    display(vec5);
    return 0;
}