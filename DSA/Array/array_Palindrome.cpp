#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

int arrayPalindrome(int arr[], int n){
    int p1 = 0, p2 = n - 1; int merge = 0;
    while (p1 <= p2){
        if (arr[p1] == arr[p2]){
            p1++; p2--; n--;
        }
        else {
            if (arr[p1] > arr[p2]){
                p2--;
                arr[p2] +=  arr[p2 + 1];
            }
            else{
                p1++;
                arr[p1] += arr[p1 - 1];
            }
            merge ++;
        }
    }
    return merge;
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);
    cout << arrayPalindrome (arr, n);
    return 0;
}