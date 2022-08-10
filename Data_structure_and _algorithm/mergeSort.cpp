#include <iostream>
using namespace std;

void merge(int arr[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int temp[high];

    while (i<=mid && j<=high)
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
    
        while (j<=high)
        {
            temp[k] = arr[j];
            k++; j++;
        }   
    
        while (i<=mid)
        {
            temp[k] = arr[i];
            k++; i++;
        }   
    

    for (int x=low ; x<high; x++)
    {
        arr[x] = temp [x];
    }
}

void mergeSort(int arr[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

int main()
{
    // int n; 
    // cout << "Enter the size: ";
    // cin >> n;

    // int arr[n];
    // for (int i=0 ; i)
    int arr[] = {7,4,1,9,2};
    mergeSort(arr,0 ,5);
    for (int i=0 ; i < 5; i++){
        cout << arr[i] << " ";
    }

}

