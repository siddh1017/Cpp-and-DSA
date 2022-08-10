#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
}

int min_element (int arr[], int n){
    int min = 0;
    for (int i = 1; i < n; i++){
        if (arr[i] < arr[0]){
            min = i;
            break;
        }
    } 
    return min;
}

int sum_pair (int arr[], int n, int x){
    int p1 = min_element(arr, n), p2 = p1 - 1;
    pair <int , int> ans; int cnt = 0;
    while (p1 != p2){
        if (arr[p1] + arr[p2] == x){
            cnt++;
            if(p1 == (p2 - 1 + n) % n){
                return cnt;
            }
             
            p1 = (p1 + 1) % n;
            p2 = (p2 - 1 + n) % n;
        }
        else if (arr[p1] + arr[p2] < x)
            p1 = (p1 + 1) % n;
        else
            p2 = (n + p2 - 1)%n;
    }
    return cnt;
}

// https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/
int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);
    return 0;
}