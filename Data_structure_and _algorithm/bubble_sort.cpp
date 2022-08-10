#include <iostream>
using namespace std;

void display(int n, int *arr)
{
    for (int i=0; i<n ;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int n, int *arr)
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

int main()
{
    int n;
    cout << "No. of ele.: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    bubble_sort(n, arr);
    display (n, arr);
    return 0;
}