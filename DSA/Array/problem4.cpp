#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
}

bool check_repeat(int arr[], int n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] == arr[j]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter the no. of elements: ";
    cin >> n;
    
    int arr[n];
    input(arr, n);
    cout << check_repeat(arr, n);

    return 0;
}