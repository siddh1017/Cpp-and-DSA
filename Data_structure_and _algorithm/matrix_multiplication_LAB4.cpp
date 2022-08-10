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

void print (vector<vector<int >> vec){
    
    for (vector<int> v : vec){
        for (int x : v){
            cout << x << " ";
        }
        cout << endl;
    }
}

// conventional method for matrix multiplication
vector<vector<int>> mutltiply (vector<vector<int>> &mat1, vector<vector<int>> &mat2, int n){

    vector<vector<int>> ans;
    for (int i=0; i< n; i++){
        for (int j=0 ; j < n;  j++){
            ans [i][j] = 0;
            for (int k=0 ; k < n; k++){
                ans[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
    return ans;
}

// recursive method for matrix mutliplication
void recursive_multiplication(vector<vector<int>> &mat1, vector<vector<int>> &mat2, vector<vector<int>> &mat3, int top1, int left1, int top2, int left2, int size)
{
    if (size == 1){
        mat3[top1][left2] += mat1[top1][left1] * mat2[top2][left2];
    }
    else{
        recursive_multiplication(mat1, mat2, mat3, top1,left1, top2, left2, size / 2);
        recursive_multiplication(mat1, mat2, mat3, top1, left1 + size / 2, top2 + size / 2, left2, size / 2);

        recursive_multiplication(mat1, mat2, mat3, top1, left1, top2, left2 + size / 2, size / 2);
        recursive_multiplication(mat1, mat2, mat3, top1, left1 + size / 2, top2 + size / 2, left2 + size / 2, size / 2);

        recursive_multiplication(mat1, mat2, mat3, top1 + size / 2, left1, top2, left2, size / 2);
        recursive_multiplication(mat1, mat2, mat3, top1 + size / 2, left1 + size / 2, top2 + size / 2, left2, size / 2);

        recursive_multiplication(mat1, mat2, mat3, top1 + size / 2, left1, top2, left2 + size / 2, size / 2);
        recursive_multiplication(mat1, mat2, mat3, top1 + size / 2, left1 + size / 2, top2 + size / 2, left2 + size / 2, size / 2);
    }
}

int main()
{
    int n;
    cout << "Enter the size of matrix: ";
    cin >> n;

    vector<vector<int>> vec1;
    input(vec1, n);
    print(vec1);

    vector<vector<int>> vec2;
    input(vec2, n);

    // conventional method
    vector<vector<int>> vec3;
    vec3 = mutltiply(vec1, vec2, n);
    print(vec3); 

    // recurssive method  
    vector<vector<int>> vec4;
    recursive_multiplication(vec1, vec2, vec4, 0,0,0,0,n);
    print(vec4);
    return 0;
}