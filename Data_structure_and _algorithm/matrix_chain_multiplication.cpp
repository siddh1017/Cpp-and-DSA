#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the no. of Matrix : ";
    cin >> n;

    int dimensions[n + 1];
    cout << "Enter the dimnesions: " << endl;
    for (int z = 0; z < n + 1; z++)
    {
        cin >> dimensions[z];
    }

    int cost_matrix[n][n];  //crearing the cost matrix

    for (int i = 0; i < n; i++)  // filling the other by 0
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                cost_matrix[i][j] = 0;
            }
        }
    }

    int i, j, k, cost;
    int diff = n - 1;

    for (int d = 1; i <= diff; d++)  // looping for the diiferent no. of matrix to be multiplied
    {
        for (i = 1; i <= n - d; i++)
        {
            j = i + d;
            int min_cost = INT_MAX;
            for (int k = i; k < j; k++)
            {
                cost = cost_matrix[i][k] + cost_matrix[k + 1][j] + (dimensions[i - 1] * dimensions[j] * dimensions[k]);  // dynamic formula 
                if (cost < min_cost){
                    min_cost = cost;
                }
            }
            cout << "lowest cost for mtarix " << i << " -> " << j << " = " << cost;
            cost_matrix[i][j] = cost;
        }
    }

    for (int i = 0; i < n; i++)   // diplaying the cost matrix
    {
        for (int j = 0; j < n; j++)
        {
            cout << cost_matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}