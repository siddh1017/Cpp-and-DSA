#include <iostream>
#include <vector>
using namespace std;


void Algorithm (vector<int> arr){
    vector<pair<int, int>> inversions;   // inversion paris arr
    for (int i = 0; i < arr.size(); i++){   // from 0 to n
        for (int j = i + 1; j < arr.size(); j++){   // i to n
            if (arr.at(i) > arr.at(j)){   // if condition holds add pair
                inversions.push_back(make_pair(i + 1, j + 1));
            }
        }
    }
    // printing the pairs
    cout << "Inversion pairs are: " << endl;
    for (int i = 0; i < inversions.size(); i++){
        cout << "(" << inversions[i].first << ", " << inversions[i].second << ")" << endl;
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
    return 0;
}