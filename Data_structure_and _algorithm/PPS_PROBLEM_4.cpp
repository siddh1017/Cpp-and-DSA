#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the non-negative integer: ";
    cin >> n;

    vector<pair<int , int>> solution;
    int x, y, count = 0;
    for (x = 0; x*x <= n; x++){
        for (y = 0; x*x + y*y <= n; y++){
            solution.push_back(make_pair(x, y));
            count++;
        }
    }

    cout << "No. of Solution = " << count << endl;
    cout << "Sloutions:" << endl;
    for (int i=0; i<count; i++){
        cout << "(" << solution[i].first << ", " << solution[i].second << ") ";
    } 
    return 0;
}