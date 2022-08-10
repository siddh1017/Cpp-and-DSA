#include <iostream>
#include <vector>
using namespace std;

// finding the minimum no. 
int smallest (vector<int> arr, int index){
    int min = INT_MAX;
    for (int i=index; i<arr.size(); i++){
        if (arr.at(i) <= min){
            min = arr.at(i);
            index = i;
        }
    }
    return index;  // retruning minimum no. index
}

// printing the array
void print(vector<int> arr){
    for (auto x : arr){
        cout << x << " ";
    }
}

void Algorithm (vector<int> &arr){  // main algortihm 
    int min;
    for (int i=0; i<arr.size()-1; i++){   // iterating for n-1 time
        min = smallest(arr, i);  // finding the min element index
        swap(arr.at(i), arr.at(min));  // swaping it with current iterator
    }
}

int main()
{
    int n; // no. of elements
    cout << "Enter the elements: ";
    cin >> n;

    vector<int> arr;
    int ele;
    cout <<  "Enter the elements: " << endl;
    for (int i=0; i<n ; i++){
        cin >> ele;
        arr.push_back(ele);
    }
    Algorithm(arr);
    cout << "After Sorting: ";
    print(arr);
    return 0;
}