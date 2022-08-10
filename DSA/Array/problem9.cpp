#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
}    

void function (int arr[], int n){
    int temp[n];
    for (int i = 0; i<n ;i++){   // reference array to keep track of the visited numbers
        temp[i] = 0;
    }
    for (int i = 0; i < n; i++){
        if (temp[arr[i] - 1] == 0){   // if the no. is not visited
            temp[arr[i] - 1] = 1;   // mark as visited
        }
        else if (temp[arr[i] - 1] == 1){   // if the no. is already visited (=1)
            cout << arr[i]  << " is repeating" << endl;    // display
        }
    }
    for (int i = 0; i < n; i++){   
        if (temp[i] == 0){    // missing no. index value will be equal to 0 
            cout << "Missing no. is " << i + 1;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);
    function(arr, n);
    return 0;
}