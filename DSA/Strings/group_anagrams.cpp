#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void input (vector<string> &vec, int n){
    string str;
    cout << "Enter the strings: ";
    for (int i = 0; i < n; i++){
        cin >> str;
        vec.push_back(str);
    }
}

vector<vector<string>> groupAnagrams (vector<string> &vec){
    
    unordered_map <string, vector<string>> myMap;
    string original;

    for (int i = 0; i < vec.size(); i++){
        original = vec[i];
        sort(vec[i].begin(), vec[i].end());
        myMap[vec[i]].push_back(original);
    }

    vector<vector<string>> ans;
    for (auto itr : myMap){
        ans.push_back(itr.second);
    }
    return ans;
} 

vector<vector<string>> groupAnagrams (vector<string> &vec){
    map<map<char, int>, vector<string>> myMap;

    for (int i = 0; i < vec.size(); i++){
        map<char, int> count; vector<string> list;
        for (int j = 0; j < vec[i].size(); j++){
            count[vec[i][j]]++;
        }
        auto it = myMap.find(count);
        if (it != myMap.end()){
            it->second.push_back(vec[i]);
        }
        else{
            list.push_back(vec[i]);
            myMap.insert({count, list});
        }
    }

    vector<vector<string>> ans;
    for (auto itr : myMap){
        ans.push_back(itr.second);
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter no. of string: ";
    cin >> n;

    vector<string> str;
    input(str, n);

    

    return 0;
}