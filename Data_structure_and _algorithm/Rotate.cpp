#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    vector <int> vec {1, 2, 3, 4, 5, 6, 7};
    rotate(vec.begin(), vec.begin() + 2, vec.end() - 1);
    for (auto x: vec){
        cout << x << " ";
    }
   
}