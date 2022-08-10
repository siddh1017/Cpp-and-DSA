#include<bits/stdc++.h>
using namespace std;

void input(vector<pair<int, int>> &pair, int n){
    int fst, sec;
    for (int i = 0; i < n; i++){
        cin >> fst >> sec;
        pair.push_back(make_pair(fst, sec));
    }
}

void mergeOverlapping (vector<pair<int, int>> &pairs){
    sort(pairs.begin(), pairs.end());
    for (int i = 1; i < pairs.size(); i++){
        if (pairs[i - 1].second > pairs[i].first){
            pairs[i - 1].second = max (pairs[i].second, pairs[i-1].second);
            pairs.erase(pairs.begin() + i);
        }
    }    
}

int main()
{
    int n;
    cout << "Enter the no. of elements : ";
    cin >> n;

    vector <pair<int, int>> pair;
    input(pair, n); 
    mergeOverlapping(pair);

    cout << pair.size() << endl;
    for (int i = 0; i < pair.size(); i++){
        cout << pair[i].first << " " << pair[i].second;
    }

    return 0;
}