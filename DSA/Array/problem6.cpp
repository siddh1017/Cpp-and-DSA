#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
}

int modified_binary(int arr[], int n, int key){
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if (arr[mid] == key){
            return mid;
        }
        if (arr[low] < arr[mid]) {   // indicates that left part is sorted 
            if (key < arr[mid] && key >= arr[low]){   // checking if the key is present in that range or not
                high = mid - 1;     // if the element is in range, divide it in half again on left     
            }
            else{
                low = mid + 1;   // if element is not in range then we will discard that portion 
            }
        }
        else{
            if (key > arr[mid] && key <=arr[high]){   // checking if the key is present in that range or not
                low = mid + 1;          // if the element is in range, divide it in half again on right
            }
            else{
                high = mid - 1;      // if element is not in range then we will discard that portion  
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);

    int key;
    cout << "Enter the element to be founeded : ";
    cin >> key;

    cout << modified_binary(arr, n, key);
    return 0;
}