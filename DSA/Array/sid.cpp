#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> arr = {1, 2, 5, 3, 5, 3, 4};
    vector<int> store; fill(store.begin(), store.end(), 0);
    
    cout << "siddh";
    for (int i = 0; i < 7; i++){
        store[arr[i]]++;
        if (store[arr[i]] > 0){
            cout << "true";
            break;
        }
    }  
    cout << "siddh";
    return 0;
}