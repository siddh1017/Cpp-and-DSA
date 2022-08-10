// ADJANCENCY_LIST_METHOD

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n; //no_of_elements
    cout << "Enter the no. of element: ";
    cin >> n;

    // int value[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> value[i];
    // }

    // vector<pair<int, int>> arr[n]; //
    // for (int i = 0; i < n; i++)
    // {

    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << "want pair " << value[i] << " and " << value[j] << " y/n? ";
    //         char select;
    //         cin >> select;
    //         if (select == 'y')
    //         {
    //             int weight;
    //             cout << "Enter the weight: ";
    //             cin >> weight;
    //             arr[i].push_back(make_pair(value[j], weight));
    //         }
    //     }
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << value[i] << " ";
    //     for (int j=0 ; j< arr[i].size(); j++)
    //     {
    //         cout << "-> " << arr[i][j].first << " weight: " << arr[i][j].second << " ";
    //     }
    //     cout << endl;
    // }

    int e;   // no_of edges
    cout << "Enter the no. of edges: ";
    cin >> e;
 
    vector<pair<char, int>> arr[n];
    for (int i = 0; i < e; i++)
    {
        char source, dest;
        int weight;
        cin >> source >> dest >> weight;
        arr[source].push_back(make_pair(dest, weight));
    }

    for (int i=0 ; i<n ; i++)
    {
        cout << arr[0][i].first << " ";
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << "-> " << arr[i][j].first << " weight: " << arr[i][j].second << " ";
        }
    }

    return 0;
}