#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
}

void sort(int n, int *arr)
{
    int is_sort = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        { 
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                is_sort = 0;
            }
            if (is_sort)
                cout << "Already sorted" << endl;
                return;
        }
    }
}

int function(int arr[], int n, int m){
    sort(n, arr);
    int min_diff = INT_MAX;
    for (int i = 0; i <= n - m; i++){
        if ((arr[i + (m-1)] - arr[i]) < min_diff){
            min_diff = arr[i + (m-1)] - arr[i];
        }
    }
    return min_diff;
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);

    int m;
    cout << "Enter the no. of children : ";
    cin >> m;

    cout << "Minmum Difference: " << function(arr, n, m);
    return 0;
}