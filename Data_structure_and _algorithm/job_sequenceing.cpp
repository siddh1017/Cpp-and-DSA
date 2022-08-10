#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool comparator (pair<int, int> a, pair <int, int> b){
    return a.first > b.first;
}

void job_sequencing(vector<pair<int, int>> vec){
    
    int time = INT_MIN;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].second > time) {
            time = vec[i].second;
        }
    }
    vector<int> sequence;
    for (int i = 0; i < time; i++){
        sequence.push_back(0);
    }

    sort(vec.begin(), vec.end(), comparator);
    for (int i=0 ; i<vec.size(); i++){
        cout << vec[i].first << " " << vec[i].second << endl;
    }
    
    int count = 0 ;
    for (int i=0; i<vec.size(); i++){
        if (count > time){
            break;
        }
        for (int j = vec[i].second; j >= 0; j++){
            if (sequence[j - 1] == 0){
                cout << "count: " << count << endl;
                sequence[j - 1] = vec[i].first;
                count ++;
                break;
            }
        }
    }
    for (auto x : sequence)
        cout << x << " ";
}


int main()
{
    int n;
    cout << "Enter the no. of jobs: ";
    cin >> n;

    vector <pair<int, int>> job;
    cout << "Enter the deadlines and profit" << endl;

    int deadline, profit; 
    for (int i=0; i<n ; i++){
        cout << "Profit: ";
        cin >> profit;
        cout << "Deadline: ";
        cin >> deadline;
        job.push_back(make_pair(profit, deadline));
    }
    job_sequencing (job);

    // vector<int> job_sequence = job_sequencing (job);
    // for (auto x : job_sequence)
    //     cout << x << " ";

    return 0;
}