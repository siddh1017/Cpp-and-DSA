#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &vec, int row, int column){ // in column and row
    for (int i = 0; i < vec.size(); i++) {
        if (vec[row][i] || vec[i][column])
        {
            return false;
        }
    }
    for (int i = row, j = column; i < vec.size() && j < vec.size(); i++, j++){ // in right below diagonal
        if (vec[i][j]){
            return false;
        }
    }
    for (int i = row , j = column; i >= 0 && j >= 0; i--, j--){ // in left upper diagonal
        if (vec[i][j]){
            return false;
        }
    }
    for (int i = row, j = column; i < vec.size() && j >= 0; j--, i++){
        if (vec[i][j]){
            return false;
        }
    }
    for (int i = row, j = column; j < vec.size() && i >= 0; j++, i--){
        if (vec[i][j]){
            return false;
        }
    }
    return true;
}

bool place_queen(vector<vector<int>> &vec, int row){
    if (row == vec.size() - 1)
        return true;
    
    for (int column = 0; column < vec.size(); column++){
        if (isSafe(vec, row, column)){
            vec[row][column] = 1;
            if (place_queen(vec, row + 1))
                return true;
            vec[row][column] = 0;
        }
    }
    return false;
}

void print_place(vector<vector<int>> &vec)
{
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
    cout << "Enter the size of chess vec: ";
    cin >> n;

    vector<vector<int>> vec;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j < n; j++)
        {
            temp.push_back(0);
        }
        vec.push_back(temp);
    }
    place_queen(vec, 0);
    print_place(vec);
    return 0;
}