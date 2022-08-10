#include <iostream>
#include <vector>
using namespace std;

void input(vector<vector<int>> &vec, int size)
{
    int ele;
    for (int i = 0; i < size; i++)
    {
        vector<int> row;
        for (int j = 0; j < size; j++)
        {
            cin >> ele;
            row.push_back(ele);
        }
        vec.push_back(row);
    }
}

void print(vector<vector<int>> vec)
{

    for (vector<int> v : vec)
    {
        for (int x : v)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

void print_matrix(vector<vector<int>> mat)
{
    int n = mat.size(), i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

void square_matrix_multiply_recursive(vector<vector<int>> &mat1, vector<vector<int>> &mat2, vector<vector<int>> &mat3, int top1, int left1, int top2, int left2, int size)
{
    if (size == 1){
        mat3[top1][left2] += mat1[top1][left1] * mat2[top2][left2];
    }
    else{
        square_matrix_multiply_recursive(mat1, mat2, mat3, top1,left1, top2, left2, size / 2);
        square_matrix_multiply_recursive(mat1, mat2, mat3, top1, left1 + size / 2, top2 + size / 2, left2, size / 2);

        square_matrix_multiply_recursive(mat1, mat2, mat3, top1, left1, top2, left2 + size / 2, size / 2);
        square_matrix_multiply_recursive(mat1, mat2, mat3, top1, left1 + size / 2, top2 + size / 2, left2 + size / 2, size / 2);

        square_matrix_multiply_recursive(mat1, mat2, mat3, top1 + size / 2, left1, top2, left2, size / 2);
        square_matrix_multiply_recursive(mat1, mat2, mat3, top1 + size / 2, left1 + size / 2, top2 + size / 2, left2, size / 2);

        square_matrix_multiply_recursive(mat1, mat2, mat3, top1 + size / 2, left1, top2, left2 + size / 2, size / 2);
        square_matrix_multiply_recursive(mat1, mat2, mat3, top1 + size / 2, left1 + size / 2, top2 + size / 2, left2 + size / 2, size / 2);
    }
}

int main()
{
    int n;
    cout << "Enter the dimenssions of matrix: ";
    cin >> n;

    vector<vector<int>> mat1;
    input(mat1, n);
    print(mat1);

    vector<vector<int>> mat2;
    input(mat2, n);
    print(mat2);
    return 0;
}