#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
}

int modified_binary(int arr[], int n){
    int low = 0, high = n - 1;
    int key = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (arr[mid] < key){
            key = arr[mid];
        }
        if (arr[low]  < arr[mid]){
            if (arr[mid-1] < arr[])
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);

    int key;
    cout << "Enter the element to be founeded : ";
    cin >> key;

    cout << modified_binary(arr, n, key);
    return 0;
}