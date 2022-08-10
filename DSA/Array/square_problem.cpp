#include <iostream>
#include <vector>
using namespace std;

void input (vector<int> &vec, int n){    // input function
    int ele;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++){
        cin >> ele;
        vec.push_back(ele);
    }
}

vector<int> non_descending_sq_array (vector<int> vec){
    int pivot, temp;
    for (int i = 0; i < vec.size(); i++){  // O(n)
        if (vec.at(i) > 0){
            if (i == 0){
                temp = i;
            }
            else{
                temp = i - 1;
            }
            pivot = i;
            break;
        }
    }

    vector<int> ans; int ele; // element to be inserted in ans array
    while (pivot < vec.size() || temp > 0){   // O(n) 
        if (vec.at(pivot) <= vec.at(abs(temp))){
            ele = vec.at(pivot)*vec.at(pivot);
            pivot ++;
        }
        else{
            ele = vec.at(temp)*vec.at(temp);
            temp --;
        }
        ans.push_back(ele);  
    }
    return ans;
}

int main()
{
    vector <int> arr;
    int n;     // no. of elements 
    cout << "Enter the number of elements: ";
    cin >> n;
    input(arr, n);

    vector<int> ans = non_descending_sq_array(arr);
    cout << "Resultant array: ";
    for (auto x : ans){
        cout << x << " ";
    }
    
    return 0;
}