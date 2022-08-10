#include <iostream>
#include <vector>
using namespace std;

int max(int &x, int &y){
    if (x > y){
        return x;
    }
    else{
        return y;
    }
}

int kanpsack(vector<pair<int, int>> vec, int capacity){
    int dp[vec.size() + 1][capacity + 1];
    cout << vec.size() + 1 << " " << capacity + 1 << endl;
    for (int i = 0; i < vec.size() + 1; i++){
        for (int j = 0; j < capacity + 1; j++){
            if (i == 0 || j == 0){  // if the bag capacity is 0 (i == 0) or if there is no item (j == 0)
                dp[i][j] = 0;
            } 
            else if (j >= vec[i-1].second){
                dp[i][j] = max(dp[i-1][j], vec[i-1].first + dp[i-1][i - vec[i-1].second]);
                // cout << "i: "<< i << "value: " << dp[i][j] << endl;
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[vec.size()][capacity];
}

int main()
{
    int items;
    cout << "Enter the no. of items: ";
    cin >> items;

    vector<pair<int, int>> vec;
    int weight, profit;
    for (int i=0; i<items; i++){
        cout << "Profit: ";
        cin >> profit;
        cout << "weight: ";
        cin >> weight;
        vec.push_back(make_pair(profit, weight));
    }

    int capacity;
    cout << "Enter the capacity of the bag: ";
    cin >> capacity;

    cout << kanpsack(vec, 10);

    return 0;
}