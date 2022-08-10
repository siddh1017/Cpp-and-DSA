#include <iostream>
using namespace std;


void reverse(int arr[], int start, int end){
    while (start < end)
    {
        cout << "called";
        swap(arr[start], arr[end]);
        start ++;
        end --;
    }
}
int main()
{
    // int arr[] = {1, 3, 5, 6, 2, 5, 7};
    // reverse(arr, 3, 6);
    // for (int i = 0; i < 7; i++){
    //     cout  << arr[i] << " "; 
    // }

    // bool arr[6];
    // for (int i =0; i < 6 ; i++){
    //     cout << arr[i] << endl;
    // }

    cout << min (6, 3);
    return 0;
}