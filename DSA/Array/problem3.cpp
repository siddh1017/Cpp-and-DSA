#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
}

void output(int arr[], int n){
    for (int i=0; i < n; i++){
        cout << arr[i] << " ";
    }
}

bool isAllNegative(int arr[], int n){
    for (int i=0; i<n; i++){
        if (arr[i] >= 0){
            return false;
        }
    }
    return true;
}

int max_subArray(int arr[], int n){
    int max_sum = INT_MIN;
    int sum = 0;
    if (isAllNegative){
        int temp = INT_MIN;
        for (int i = 0; i < n; i++){
            if (arr[i] > temp){
                temp = arr[i];
            }
        }
        return temp;
    }
    else{
        for (int i=0; i<n; i++){
            sum += arr[i];
            if (sum < 0){
                sum = 0;
            }
            if (sum > max_sum){
                max_sum = sum;
            }
        }
        return max_sum;
    }
}


int main()
{
    int n;
    cout << "Enter the no. of elements";
    cin >> n;
    
    int arr[n];
    input(arr, n);
    cout << max_subArray(arr, n);
    // output(arr, n);
    return 0;
}