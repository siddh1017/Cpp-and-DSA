#include <iostream>
#include <vector>
using namespace std;

// main algo 
void Algorithm (vector<int> &arr){
    bool is_sort = 1;  // for checking whether its already sorted
    for (int i = 0; i < arr.size(); i++){  // iterating through array
        for (int j = 0; j < arr.size() -i - 1; j++){  // iterating from 0 to last sorted element
            if (arr.at(j) > arr.at(j+1)){   // swap if condition
                swap(arr.at(j), arr.at(j+1));
                is_sort = 0;
            }
        }
        if (is_sort){  // if its already sorted
            cout << "Already sorted" << endl;
            return;
        }
    }
}
// printing the array
void print(vector<int> arr){
    for (auto x : arr){
        cout << x << " ";
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
    cout << "After sorting: ";
    print(arr);
    return 0;
}