#include <bits/stdc++.h>
using namespace std;  
 
template <class T>
// Insertion sort using the STL  
void insertionSort(vector<T> &vec)
{
    for (auto it = vec.begin(); it != vec.end(); it++)  
    {        
        auto const insertion_point = upper_bound(vec.begin(), it, *it);  
        // finding postion just smaller than respectove no.
        rotate(insertion_point, it, it+1);        
        // rotating the array between insertion point and the iterator it by 1 
    }
}



// insertion Sort 
void insertion_sort(vector<int> &vec)
{
    int temp, precedence;
    for (int i = 1; i < vec.size() ; i++)
    {
        temp = vec.at(i);
        precedence = i-1;

        while (precedence >= 0  && vec.at(precedence) > temp)  
        {
            vec.at(precedence+1) = vec.at(precedence);
            precedence--; 
        }
        vec.at(precedence+1) = temp; 
    }
}

 
template <class T1>
void print(vector<T1> vec)
{
    for(T1 x : vec)
        cout << x << " ";
    cout << endl;
}

template <class type>
void input(vector<type> &v)
{
    int size;
    type ele;
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
    // TASK_1 -> implement insertion sort for integer array
    vector<int> arr;
    input(arr);
    cout << "Before Sorting --> " << endl;
    print (arr);

    insertion_sort(arr);
    cout << "After sorting --> " << endl;
    print(arr);

    // TASK_2 -> implement insertion sort using STL for integer array 
    vector <int> arr1;
    input(arr1);
    cout << "Before Sorting --> " << endl;
    print (arr);

    cout << "Using STL for Insertion Sort: " << endl;
    cout << "After sorting --> " << endl;
    insertionSort(arr1);

    // TASK_3 -> implement insertion sort to sort charchters using the STL 	
    vector <char> arr2;
    input(arr2);
    cout << "Before Sorting --> " << endl;
    print(arr2);

    cout << "Using STL for Insertion Sort: " << endl;
    insertionSort(arr2);
    cout << "After sorting --> " << endl;
    print(arr2);
    
    return 0;
}