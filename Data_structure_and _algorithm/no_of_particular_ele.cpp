#include <iostream>
#include <vector>
using namespace std;

void NumberOfElements(vector<int> ar) {
    int count;
    for (int i=0; i<ar.size(); i++){
        count = 1;
        if (ar.at(i) != -1)
        {
            for (int j = i+1; j<ar.size(); j++)
            {
                if (ar.at(i) == ar.at(j))
                {
                    count ++;
                    ar.at(j) = -1;
                }
            }
            cout << "ele: " << ar.at(i) << " ";
            cout << "count: " << count << endl;
        }
        else 
        {
            continue;
        }
    } 
}

int main()
{
    vector <int> arr = {1, 1, 3, 1, 2, 1, 3, 3, 3, 3};
    NumberOfElements(arr);
    return 0;
}