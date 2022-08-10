#include <iostream>
using namespace std;

void insertion_sort(int n, int *arr)
{
    int temp, precedence;
    for (int i = 1; i < n; i++)
    {
        temp = arr[i];
        precedence = i-1;

        while (precedence >= 0  && arr[precedence] > temp)
        {
            arr[precedence+1] = arr[precedence];
            precedence--; 
        }
        arr[precedence+1] = temp; 
    }
}

void display(int n, int *arr)
{
    for (int i = 0; i < n; i++)
    {
        cout << "ele " << i+1 << " = "  << arr[i] << endl ;
    }
}

int main()
{
    int n;
    cout << "no. of ele: ";
    cin >> n;

    int arr[n];
    cout << "Enter the ele.:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertion_sort(n, arr);
    display(n, arr);
    return 0;
}