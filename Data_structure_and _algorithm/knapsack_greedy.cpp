#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void knapsack(int weight[], int profit[], int bag_size, int size){
    
    vector<pair<int ,int>> vec;  // maintaing weight and profitByweight array
    for (int i = 0; i < size; i++){
        vec.push_back(make_pair(profit[i]/weight[i], weight[i]));
    }

    sort(vec.begin(), vec.end());  // sorting in max. profit wise

    vector <int> bag; int max_profit = 0; 

    for (int i = size-1; i >= 0; i--){  
        if (vec[i].second < bag_size){  // if the weight of the given item is less than bag size
            bag.push_back(vec[i].second);  // enter that weight completely in bag
            max_profit += (vec[i].second*vec[i].first);  // incrementing the profit
            bag_size -= vec[i].second; // decrementing the bag size
            cout << "current bag size: " << bag_size << endl;
        }
        else{  // if the bag size is less than current weight
            bag.push_back(bag_size);
            int part_profit = bag_size*vec[i].first;  // adding the fraction of weight that can fill bag
            max_profit += part_profit;  // incrementing the profit 
            break;   // as no space will be left in bag by now
        }
    }
    cout << "Contents in bag:" << endl;
    for (auto x : bag){  // displaying weights in bag
        cout << x << " ";
    }
    cout <<  endl;
    cout << "Maximum profit: " << max_profit;
}

int main()
{
    int n; // no. of items;
    cout << "Enter the no. of items: ";
    cin >> n;

    int bag_size;
    cout << "Enter the bag size: ";
    cin >> bag_size;

    int profit[n]; int weight[n];

    for (int i = 0; i < n; i++) {
        cout << "Weight: " ;
        cin >> weight[i];
        cout << "Profit: ";
        cin >> profit[i];
    }

    knapsack(weight, profit, bag_size, n);

    return 0;
}