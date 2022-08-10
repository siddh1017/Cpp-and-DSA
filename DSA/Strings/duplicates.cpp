// C++ program to count all duplicates
// from string using maps
#include <bits/stdc++.h>
using namespace std;
void printDups(string str)
{
    unordered_map <char, int> dup;
    for (int i = 0; i < str.length(); i++){
        dup[str[i]]++;
    } 
    for (auto it : dup){
        if (it.second > 1){
            cout << it.first << " : " << it.second << endl;
        }
    }
}
/* Driver code*/
int main()
{
    string str = "sssa ash haha";
    printDups(str);
    return 0;
}