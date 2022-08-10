#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
} 

void productExpectSelf(int arr[], int n){
    int ans[n]; ans[0] = arr[0];
    for (int i = 1; i < n; i++){
       ans[i] = ans[i]*arr[i]; 
    }

    int product = 1;
    ans[n-1] = ans[n-2];
    for (int i = n-2; i < 1; i++){
        
    }
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);
    
    return 0;
}