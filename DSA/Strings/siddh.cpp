// C++ program to find the length of the longest substring
// without repeating characters
#include <bits/stdc++.h>
using namespace std;
 
int longestUniqueSubsttr(string str)
{
    int n = str.size(); int ans = 0;

    for (int i = 0; i < n; i++){
        vector<bool> visited(256);
        for (int j = i; j < n ; j++){
            if (visited[str[j]]){   // if the letter is visited 
                break;
            }
            else{
                ans = max (ans, j - i + 1);  // selecting the max size ( j-i-1  is the size of the current window whichh changes as j)
                visited[str[i]] = true;   
            }
        }
        visited[str[i]] = false;  // removing the first charater of window 
    }
    return ans;
}
 
// Driver code
int main()
{
    string str = "sid";
    cout << "The input string is " << str << endl;
    int len = longestUniqueSubsttr(str);
    cout << "The length of the longest non-repeating "
            "character substring is "
         << len;
    return 0;
}