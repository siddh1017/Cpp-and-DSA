#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

int max_water (int arr[], int n){
    int p1 = 0, p2 = n-1;
    int max_area = (p2 - p1) * min(arr[p1], arr[p2]);
    while (p1 < p2){
        if (arr[p2] > arr[p1]){
            p1++;
        }
        else{
            p2--;
        }
        max_area = max (max_area, (p2 - p1) * min(arr[p1], arr[p2]));
    }
    return max_area;
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);
    return 0;
}