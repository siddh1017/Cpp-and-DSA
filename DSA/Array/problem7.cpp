#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
}

void revers(int arr[], int start, int end){
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start ++;
        end --;
    }
}


void next_permutation(int arr[], int n){
    int temp, index; 
    for (int i = n - 1; i >= 0; i--){  // finding the index which breaks descending order
        if (i == 0){
            revers(arr, 0, n-1);
            return;
        }
        if (arr[i] > arr[i - 1]){
            temp = i - 1;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--){   // the no. greater than no. at index on temp
        if (arr[i] > arr[temp]){
            index = i;
            break;
        }
    }
    swap(arr[temp], arr[index]);  // swaping 
    revers(arr, temp + 1, n - 1);   // reversing rest end part of array
}

void output(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);
    next_permutation(arr, n);
    output(arr, n);
    return 0;
}