#include <iostream>
#include <map>
using namespace std;

int main()
{
    map <int , int >arr;
    int n = 4;
    int value , map_value;
    for (int i=0; i<n; i++){
        cin >> value >> map_value;
        arr.insert(pair<int, int>(value,map_value));
    }
    for (auto itr=arr.begin(); itr != arr.end(); itr++){
        cout << itr->first << " " << itr->second << endl; 
    }

    /*
    https://www.cplusplus.com/reference/map/map/
    */
    return 0;
}