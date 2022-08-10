#include <iostream>
using namespace std;

template <class T2>
void printArray(T2 *arr, int n)
{
    cout << "print" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <class T>
void merge(T arr[], int mid, int low, int high)
{
    int i, j, k;
    T temp[high];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }
    
}

template <class T1>
void mergeSort(T1 arr[], int low, int high){
    int mid; 
    if(low < high){
        mid = (low + high) /2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, mid, low, high);
    }
}

void mergeString(string str[], int low, int mid, int high){
    int i = low , k = low;
    int j = mid + 1;
    string temp[high];
    
    while (i <= mid && j <= high)
    {
        if (str[i] > str[j])
        {
            temp[k].assign(str[i]);
            i++;
            k++;
        }
        else
        {
            temp[k].assign(str[j]);
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k].assign(str[i]);
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k].assign(str[j]);
        k++;
        j++;
    }
    for (int u = low; u <= high; u++)
    {
        str[u].assign(temp[u]);
    }
     
}

void mergeSortString(string arr[], int low, int high){
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        mergeString(arr, mid, low, high);
    }
}

int main()
{
    // TASK_1 -> merge sort to sort an integer array 
    int n;
    cout << "Enter the no. of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the integer array:" << endl;
    for (int i = 0 ; i<n ;i++) {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n-1);
    printArray(arr, n);


    // TASK_2 -> perform merge sort on the character array
    int c;
    cout << "Enter the no. of elements: ";
    cin >> c;

    char crr[c];
    cout << "Enter the character array:" << endl;
    for (int i = 0 ; i<c ;i++) {
        cin >> crr[i];
    }
    mergeSort(crr, 0, c-1);
    printArray(crr, c);

    // TASK_3 -> perform merge sort on the String array
    int s;
    cout << "Enter the no. of elements: ";
    cin >> s;

    string srr[s];
    cout << "Enter the Strings:" << endl;
    for (int i = 0 ; i<s ;i++) {
        cin >> srr[i];
    }
    
    mergeSortString(srr, 0, s-1);
    printArray(srr, n);

    return 0;
}
