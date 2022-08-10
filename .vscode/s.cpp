#include <iostream>
using namespace std;

int minimum (int arr[], int n, int min){
    int next_min = INT8_MAX;
    for (int i=0; i<n; i++){
        if (arr[i] > min && arr[i] < next_min){
            next_min = arr[i];
        }
    }
    return next_min;
}

int min_index(int arr[], int n, int min){
    int next_min = INT8_MAX;
    int index;
    for (int i=0; i<n; i++){
        if (arr[i] > min && arr[i] < next_min){
            next_min = arr[i];
            index = i;
        }
    }
    return index;
}


void sort(int arr[], int n){
     int min = minimum (arr, n ,INT8_MIN);
     for (int i=1; i<n ; i++){
         if (i==n-1 && arr[i] < arr[0]){
                 swap(arr[0], arr[i]);
         }
         else{
             int next_min = minimum(arr, n , min);
             int index  = min_index(arr, n ,next_min);
             swap (arr[i], arr[index]);
         }
     }
     for (int i=0; i<n; i++){
         cout << arr[i] << " ";
     }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, n);
    
    return 0;
}