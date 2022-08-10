#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int check_safety (vector<vector<int>> &vec, int row){
    int index = 0;
    for (auto x : vec[row]){  // checking for 0 (safe position) in row
        if (index == vec.size()-1 && x != 0){
            return -1;
        }
        else if (x == 0){
            return index;
        }
        index ++;
    }
}

void update_matrix (int index, int row, vector<vector<int>> &vec){
    int temp = row + index;
    int diff = row - index;

    for (int i=0; i<vec.size(); i++){
        for (int j=0; j<vec.size(); j++){
            if (i == row || j == index || i-j == diff || i+j == temp){
                if (i > row){
                    vec[i][j] = -1;
                }
            }
        }
    }
    vec[row][index] = 1;
}

void update_backtrack(vector<vector<int>> &vec, int row){
    // cout <<  "called " << endl;
    // cout <<  "row : " << row << endl;
    int index = 0;
    for (auto x : vec[row]){
        if ( index == vec[row].size() - 1  && x != 0){
            row--;
            update_backtrack(vec, row);
        }
        else if (x == 0){
            vec[row][index] = 1;
            update_matrix(index, row, vec);
        }
        index ++;
    }
}

void place_queen(int row, int n, vector<vector<int>> &vec){
    if (row < n){
        int pos = check_safety(vec, row);
        cout << "pos = " << pos << endl;
        if (pos == -1){
            row --;
            update_backtrack(vec, row);
        }
        else{
            update_matrix(pos, row, vec); 

            cout << "after update matrix" << endl;
            for (int i=0; i<vec.size(); i++){
                for (int j=0; j<vec.size(); j++){
                    cout << vec[i][j] << " ";
                }
                cout << endl;
            }   


            row ++;
            place_queen(row, n, vec);
        }
    }
}

void print_place (vector<vector<int>> &vec){
    for (vector<int> vec1D : vec)
    {
        for (int x : vec1D)
        {
            cout << x << " ";
        }   
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the size of chess board: ";
    cin >> n;
    
    vector<vector<int>> vec;
    for (int i=0; i<n ;i++){
        vector<int> temp;
        for (int j=0; j<n ; j++){
            temp.push_back(0);
        }
        vec.push_back(temp);
    }
    place_queen(0,n,vec);
    print_place(vec);
    return 0;
}