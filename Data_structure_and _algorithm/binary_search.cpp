#include <iostream>
using namespace std;

void binary_search(int x, int a[], int n)
{
    int iteration = 1;
    int f = 0, r = n - 1;
    int mid;
    while (f <= r)
    {
        mid = (f+r)/2;
        if (a[mid] == x)
        {
            cout << "Elemnet: " << x << " is at index: " << mid <<endl;
            cout << "Iteraion: " << iteration << endl;
            break;
        }
        else if (a[mid] > x)
        {
            r = mid - 1;
        }
        else if (a[mid] < x)
        {
            f=mid +1;
        }
        else if (f == r && a[mid]!=x)
        {
            cout << "Element not exist" << endl;
            break;
        }
        cout << a[mid] << endl;
        iteration ++;
    }
}

void linear_search (int x , int arr[], int n)
{
    int iteration = 1;
    for (int i=0 ; i<n; i++)
    {
        if (arr[i] == x)
        {
            cout << "element found" << endl;
            cout << "iteration: " << iteration << endl;
            break;
        }
        else if (i == (n-1) && arr[i] != x)
        {
            cout << "Element not exist" << endl;
        }
        else {
            iteration ++;
        }
    }
}

int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the no.'s in ascending order" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "search no.: ";
    cin >> x;
    
    cout << "binary search:" << endl; 
    binary_search(x,arr,n);

    cout << "linear search:" << endl;
    linear_search (x, arr, n);
    return 0;
}