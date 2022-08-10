#include <iostream>
#include<bits/stdc++.h>
#include <vector>
using namespace std;

int uppper_bound (vector<pair<int, int>> &bag, int excluded, int bag_size){
    int value = 0, i=0;
    while (value <= bag_size) {
        if (i == excluded) {
            i++;
            continue;
        }
        value = value + bag[i].first;
        i++;
    }
    return -value;
}

int cost (vector<pair<int, int>> &bag, int excluded, int bag_size){
    int value = 0, i=0;
    while (value <= bag_size){
        if (i == excluded) {
            i++;
            continue;
        }
        if (bag[i].second > bag_size){
            int left = bag_size - value;
            value = value + left*(bag[i].first/bag[i].second);
            break;
        } 
        value = value + bag[i].first;
        i++;
    }
    
}


// sorting it in decreasing order of profit/weight to get maximum buounds
bool sortByValue(const pair<int, int> &a, const pair<int, int> &b){ 
    return (a.first/a.second > b.first/b.second);
}

void knapsack (vector<pair<int, int>> &bag, int bag_size){
    int upper_bound = 0;
    int cost = 0;
    bool final[bag.size()], pending[bag.size()];
    sort (bag.begin(), bag.end(), sortByValue);
    queue <int> que;  

    int ptr=0;
    final[0] = 1;
    que.push(final[0]);
    
    while (!que.empty()){
        int upper = upper_bound(bag, ptr, )
    }


}

int main()
{
    int n;
    cout << "Enter the no. of items: ";
    cin >> n;
    int bag_size ;
    cout << "Enter the bag size: ";
    cin >> bag_size;

    vector<pair<int, int>> bag;
    int profit, weight;
    cout << "Enter the items: " << endl;
    for (int i=0; i<n; i++){
        cout << "profit: "; cin >> profit;
        cout << "weight: "; cin >> weight;
        bag.push_back(make_pair(profit, weight));
    }

    return 0;
}