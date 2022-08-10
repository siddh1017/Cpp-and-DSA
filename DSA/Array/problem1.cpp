#include <iostream>
#include <vector>
using namespace std;

// Iterartive 
vector<pair<int, int>> max_min(vector<int> arr)
{
    int max, min;
    if (arr[0] < arr[1]){
        min = arr[0];
        max = arr[1];
    }
    else{
        min = arr[1];
        max = arr[0];
    }
    for (int i = 2; i < arr.size(); i++){
        if (arr[i] > max){
            max = arr[i];
        }
        if (arr[i] < min){
            min = arr[i];
        }
    }

    vector<pair<int, int>> Pair;
    Pair.push_back(make_pair(min, max));
    return Pair;
    
}

// Divide and Quonqer
vector<pair<int, int>> max_min_d(vector<int> arr, int low, int high){
    vector<pair<int, int>> ans, left, right;
    int min, max;
    
    if (low == high){
        ans[0].first = arr[low];
        ans[0].second = arr[low];
        return ans;
    }
    if (high = low + 1){
        if (arr[low] > arr[high]){
            ans[0].first = arr[high];
            ans[0].second = arr[low];
        }
        else {
            ans[0].first = arr[low];
            ans[0].second = arr[high];
        }
        return ans;
    }
    
    int mid = (low + high)/2;
    left = max_min_d(arr, low, mid);
    right = max_min_d(arr, mid+1, high);

    if (left[0].first < right[0].first){
        ans[0].first = left[0].first;
    }
    else{
        ans[0].first = right[0].first;
    }


    if (left[0].second > right[0].second){
        ans[0].second = left[0].second;
    }
    else{
        ans[0].second = right[0].second;
    }    
    return ans;
}

int main()
{
    int n;
    cout << "Enter the no. of the elements ";
    cin >> n;

    vector<int> arr;
    int ele;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }

    // Way-1
    vector<pair<int, int>> ans = max_min_d(arr, 0, n-1);
    cout << "Mininmum: " << ans[0].first << " Maximum: " << ans[0].second;

    // Way-2


    return 0;
}