#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &board, int row, int col){  // checking in the upper coloumn
    for (int i=0; i< row; i++){
        if (board[i][col]){
            return false;
        }
    }

    for (int i = row, j = col; i >=0 || j < board.size(); i--, j++){  // checking in the right upper diagnol
        if (board[i][j]){
            return false;
        }
    }
    
    for (int i = row, j = col; i >=0 || j >= 0 ; i--, j--){  // checking in the left upper diagnol
        if (board[i][j]){
            return false;
        }
    }
    return true;  // true if its safe to place
}

bool solveNQ(vector<vector<int>> &board, int row){
    if (row >=  board.size()){  // if we reach the last row and hence solution exist
        return true;
    }
    for (int col = 0; col < board.size(); col ++){  // iteration through all colomns for each row
        if (isSafe(board, row, col)){  // checking if queen is safe to place or not 
            board[row][col] = 1;  // if safe -> change that position value to 1
            if (solveNQ(board, row + 1)){    // solve for next row 
                return true;
            }
            board[row][col] = 0;  // if the next row doesn't lead in solution
                                  // backtrack and set that particular postion again to 0
        }
    }
    return false;  // if no solution is found
}

int main()
{
    int boardSize;
    cout << "Enter the board size: ";
    cin >> boardSize;

    vector<vector<int>> board;  // chess board
    for (int i = 0; i < boardSize; i++){  // setting all block values to 0 
        vector<int> temp;
        for (int j=0 ;j < boardSize; j++){
            temp.push_back(0);
        }
        board.push_back(temp);
    }

    if (solveNQ(board, 0)){   // if the problem is solved
        cout << "Solution exist" << endl;
        cout << "matrix view: "<< endl;
        for (vector<int> v : board){  // diplaying the board
            for (auto x : v){
                cout << x << " ";
            }
        cout << endl;
        }
    }
    else {  // if problem is not solved
        cout << "No possible Solution" << endl; 
    }
    return 0;
    
}