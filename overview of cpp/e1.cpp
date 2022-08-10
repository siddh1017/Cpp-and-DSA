#include <iostream>
using namespace std;

int sum(int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count = count + arr[i];
    }
    return count;
}

void largest(int arr[], int n)
{
    int temp_larg = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > temp_larg)
        {
            temp_larg = arr[i];
        }
    }
    cout << "The largest no. in array is: " << temp_larg << endl;
}

int search(int arr[], int x, int n, int l)
{
    int r = n - 1;
    if (r < l)
        return -1;
    if (arr[l] == x)
        return l;
    if (arr[r] == r)
        return r;
    return search(arr, x, n - 1, l + 1);
}

void check_elements(int arr[], int n, int s)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int x = arr[i] + arr[j];
            if (x == s)
            {
                cout << "The two sum elements are " << arr[i] << " and " << arr[j] << endl;
                break;
            }
        }
    }
}

void majority(int arr[], int n)
{
    int max_count = 0, count, index;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > max_count)
        {
            max_count = count;
            index = i;
        }
    }
    if (max_count > (n / 2))
    {
        cout << "The no. " << arr[index] << " occurs as majority with " << max_count << " times" << endl;
    }
    else
    {
        cout << "No Majority elemnets" << endl;
    }
}

void odd_times(int arr[], int n)
{
    int count;
    for (int i = 0; i < n; i++)
    {
        count = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count ++;
            }
        }
        if (count%2 != 0)
        {
            cout << "The no. " << arr[i] << " occurs odd no. of times" << endl;
            break;
        }
    }
}

void find_missing (int arr[], int n)
{
    int miss_total = 0;
    for (int i=arr[0]; i<arr[n-1]+1; i++)
    {
        miss_total = miss_total + i;
    }
    int total = sum(arr, n);
    int miss = total - miss_total;
    cout << "The missing element in the sequence is: " << -miss << endl; 
}

void merge (int arr1[], int arr2[], int m, int l)
{
    for (int i=0 ; i<l ; i++)
    {
        for (int j=0; j<)
    }
}

int main()
{
    int n;
    cout << "Enter the no. of the elements: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    int sum_of_elements = sum(arr, n);
    cout << "The sum of the elements is " << sum_of_elements << endl;

    largest(arr, n);

    int x, l = 0;
    cout << "Enter the no. to be searched: ";
    cin >> x;
    int index = search(arr, x, n, l);
    if (index != -1)
    {
        cout << "The element " << x << " is at index " << index << endl;
    }
    else
    {
        cout << "Element " << x << " is not present in array" << endl;
    }

    int sum_id;
    cout << "Enter the sum of elements to checked: ";
    cin >> sum_id;

    check_elements(arr, n, sum_id);
    majority(arr, n);
    odd_times (arr,n); // 1 2 3 2 1 2 3 2 1 
    find_missing (arr, n);

    int m,l;
    int m_filled, l_filled;

    cout << "Enter the size 1st array: ";
    cin >>m;
    int arr1[m];
    cout << "Enter no. of elements to be filled: ";
    cin >> m_filled;
    cout << "Enter the elements ";
    for (int i=0; i<m_filled; i++)
    {
        cin >> arr1[i];
    }

    cout << "Enter the size 2nd array: ";
    cin >> l;
    int arr2[l];
    cout << "Enter no. of elements to be filled: ";
    cin >> l_filled;
    cout << "Enter the elements ";
    for (int i=0; i<l_filled; i++)
    {
        cin >> arr2[i];
    }


    return 0;
}
 
 