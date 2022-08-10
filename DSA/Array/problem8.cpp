#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
}

bool isDecreasing(int arr[], int n){
    for (int i = 0; i < n - 1; i++){
        if (arr[i] > arr[i+1]){
            return false;
        }
    }
    return true;
}

// for one transaction allowed
int max_difference(int arr[], int n){
    int buy = arr[0], max_profit = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] < buy){
            buy = arr[i];
        }
        else if(arr[i] - buy > max_profit){
            max_profit = arr[i] - buy;
        }
    }
    return max_profit;
}

// for multiple transaction allowed
int max_profit(int arr[], int n){
    int min = arr[0], max_pft = 0;
    for (int i = 0; i < n-1; i++){
        cout << "arr[i] : " << arr[i] << " " << "arr[i+1] : " << arr[i+1] << endl;
        if (arr[i] > arr[i+1]){
            cout << "called" << endl;
            max_pft += (arr[i] - min);
            min = arr[i + 1];
        }
    }
    return max_pft;
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);

    cout << max_profit(arr, n);
    return 0;
}