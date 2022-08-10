#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *arr; int n = 4;
    for (int i= 0; n < 4; i++){
        arr[i] = rand()%4 +1;
    }

    // sort (arr, arr + n);
    for (int i=0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}