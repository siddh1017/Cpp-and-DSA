#include <iostream>
using namespace std;

void input(int arr[], int n){
    for (int i=0; i < n; i++){
        cin >> arr[i];
    }
}

// int maxProductSubArray(int arr[], int n){
//     int max_product = INT_MIN, product = 1, negativePdt = INT_MIN;
//     for (int i = 0; i < n; i++){
        // if (arr[i] <= 0){
        //     if (negativePdt < arr[i]){
        //         negativePdt = arr[i];
        //     }
        //     product = 1;
        //     continue;
        // }
//         product = product * arr[i];
//         if (product > max_product){
//             max_product = product;
//         }
//     } 
//     if (max_product > negativePdt){
//         return max_product;
//     }
//     else{
//         return negativePdt;
//     }
// }

// int maxProductSubArray(int arr[], int n){
//     int max_product_left = INT_MIN, product_left = 1, product_right = 1, max_product_right = INT_MIN, zero = INT_MIN;
//     for (int i = 0; i < n; i++){
//         if (arr[i] == 0){
//             zero = 0;
//             product_left = 1;
//             product_right = 1;
//             continue;
//         }
//         product_left = product_left * arr[i];
//         product_right = product_right * arr[n - 1 - i];
//         if (product_left > max_product_left){
//             max_product_left = product_left;
//         }
//         if (product_right > max_product_right){
//             max_product_right = product_right;
//         }
//     }
//     if (max_product_left > max_product_right){
//         return max_product_left;
//     }
//     else{
//         return max_product_right;
//     }
// }


// https://www.youtube.com/watch?v=tHNsZHXnYd4
int maxProductSubArray(int arr[], int n){
    int ans = arr[0];
    int max_product = ans, min_product = ans;
    for (int i = 1; i < n; i++){
        if (arr[i] < 0){
            swap(max_product, min_product);
        }
        max_product = max (arr[i], max_product * arr[i]);   
        min_product = min (arr[i], min_product * arr[i]);
        ans = max (ans, max_product);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    int arr[n];
    input(arr, n);
    cout << maxProductSubArray(arr, n);
    return 0;
}