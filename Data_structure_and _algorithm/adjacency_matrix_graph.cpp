#include <iostream>
using namespace std;

int main()
{
    int n; // no_of_nodes
    cout << "Enter the no. of nodes: ";
    cin >> n;

    int value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }

    cout << "Enter the distances (0 if self loop exist , -1 if not directly reachable)" << endl;
    // ADJACENCY MATRIX FORM------------------->
    // for GRAPH IS DIRECTED in
    int directed[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Distance between the " << value[i] << " and " << value[j] << ": ";
            cin >> directed[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (directed[i][j] != 0 || directed[i][j] != -1)
            {
                cout << value[i] << " -> " << value[j] << ": " << directed[i][j] << " ";
            }
            cout << endl;
        }
    }

    // for NON_DIRECTED graph
    int non_directed[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << "Distance between the " << value[i] << " and " << value[j] << ": ";
            cin >> non_directed[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            cout << value[i] << " <-> " << value[j] << ": " << non_directed[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}