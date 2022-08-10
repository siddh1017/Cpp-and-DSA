#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int weight, value;
    int bound, cost;
};

// sorting it in decreasing order of profit/weight to get maximum buounds
bool sortByValue(const pair<int, int> &a, const pair<int, int> &b){ 
    return (a.first/a.second > b.first/b.second);
}

void knapsack (vector<pair<int, int>> &bag, int bag_size){
    
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