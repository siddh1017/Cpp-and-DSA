#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int minimum_coin (vector<int> vec, int value){
    int sum = 0, count = 0 ;
    sort(vec.begin(), vec.end());
    while (sum < value){
        for (int i = 0; i < vec.size(); i++){
            if (vec.at(i) < sum){
                cout << vec.at(i) << endl;
                sum = sum + vec.at(i);
                count++;
                break;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> vec;
    int n;
    cout << "Enter the no. of denominations: ";
    cin >> n;
    
    int temp;
    cout << "Enter the denominations: " << endl;
    for (int i = 0; i < n; i++){
        cin >> temp;
        vec.push_back(temp);
    }

    int value;
    cout << "Enter the value: ";
    cin >> value; 

    cout << minimum_coin(vec, value);

    return 0;
}