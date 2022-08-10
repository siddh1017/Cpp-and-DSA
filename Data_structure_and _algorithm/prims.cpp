#include <iostream>
#include <bits/stdc++.h>
using namespace std;

# define n 5 

int selectMinVertex(vector<int>& value , vector<bool>& setMST)
{
    int min = INT_MIN;
    int vertex;
    for (int i=0; i<n ; i++)
    {
        if (setMST[i] == false && value[i] < min)
        {
            vertex = i;
            min = value[i];
        }
    }
    return vertex;
}

void prims (int graph[n][n], int value[])   // prims algorithm
{
    int parent[n];  // maintaing the parent of nodes 
    vector<int> weights (n , INT_MAX);   // creating weight vector with initial value INFINITY
    vector<bool> setMST (n, false);    // created to keep track whether nodes has been visited or not

    parent[0] = -1; // so the starting node has no parent
    weights[0] = 0; // so as it is 1st node

    for (int i=0; i<n-1; i++)
    {
        int u = selectMinVertex (weights, setMST);  // selecting the next minimum node to explore
        setMST[u] = true;  // marking that node has been visited 

        for (int j=0; j<n ; j++)
        {
            if (graph[u][j] != 0 && setMST[j]==false && graph[u][j] < weights[j])
            {
                weights[j] = graph[u][j];
                parent[j] = u;
            }
        }
    }
    for (int i=1; i<n; i++)
    {
        cout << parent[i] << " <-> " << value[i] << ": " << graph[parent[i]][value[i]] << endl;
    }
}

int main()
{
    int value[n];
    for (int i = 0; i < n; i++)  // vertex input
    {
        cin >> value[i];
    }

    cout << "Enter the distances (0 if self loop exist , -1 if not directly reachable)" << endl;
    int graph[n][n];
    for (int i = 0; i < n; i++)  // weight input if edge exist
    {
        for (int j = i; j < n; j++)
        {
            cout << "Distance between the " << value[i] << " and " << value[j] << ": ";
            cin >> graph[i][j];
        }
    }

    prims(graph, value);

    return 0;
}