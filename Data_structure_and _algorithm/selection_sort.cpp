#include <iostream>
using namespace std;

void selection_sort(int n, int *arr)
{
    int min, index;
    for (int i = 0; i < n - 1; i++)
    {
        min = arr[i];
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (min> arr[j])
            {
                min = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = min;
    }
}

void display(int n, int *arr)
{
    for (int i = 0; i < n; i++)
    {
        cout << "ele " << i + 1 << " = " << arr[i] << endl;
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
    selection_sort(n, arr);
    display(n, arr);
    return 0;
}