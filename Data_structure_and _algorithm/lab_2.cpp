#include <iostream>
using namespace std;

void printarrrrarry(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void merge(int arr[], int mid, int low, int high)
{
    int i, j, k, temp[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++; i++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        k++; j++;
    }
    for (int i = low; i <= high; i++)
        arr[i] = temp[i];
}

void mergeSort(int arr[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, mid, low, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i=0 ; i< n ; i++)
        cin >> arr[i];

    mergeSort(arr, 0 , n-1);
    printarrrrarry(arr, n);
    return 0;
}
