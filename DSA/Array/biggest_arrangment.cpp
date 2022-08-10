#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void input(vector<int> &vec, int n){
    int ele;
    for (int i = 0; i < n; i++){
        cin >> ele;
        vec.push_back(ele);
    }
}

int myCompare (string X, string Y){
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1 : 0;
}

void biggestArrangment(vector<int> &vec){
    sort(vec.begin(), vec.end(), myCompare);
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    vector<int> vec;
    input(vec, n);

    biggestArrangment(vec);

    for (int x : vec){
        cout << x;
    }

    return 0;
}