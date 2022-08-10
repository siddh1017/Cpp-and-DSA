#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
}  

int trap_water(int arr[], int n){
    int left[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++){
        left[i] = max(left[i-1], arr[i]);
    }

    int right[n];
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--){
        right[i] = max(right[i + 1], arr[i]);
    } 

    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += (min(left[i], right[i]) - arr[i]);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);
    cout << trap_water(arr, n);
    return 0;
}

// https://www.youtube.com/watch?v=UZG3-vZlFM4&t=531s