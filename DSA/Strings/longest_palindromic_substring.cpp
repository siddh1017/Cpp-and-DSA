#include <iostream>
using namespace std;

string longestPalandromicSubstring (string str){
    int n = str.length(), len = 0, start = 0;
    bool dp[n][n];

    for (int gap = 0; gap < str.length(); gap++){
        for (int i = 0, j = gap; j < str.length(); i++ ,j++){
            if (gap  == 0){
                dp[i][j] = true;
            }
            else if (gap == 1){
                if (str[i] == str[j]){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
            else{
                if (str[i] == str[j] && dp[i + 1][j - 1] == true){
                    dp[i][j] = true;
                }
                else{
                    dp[i][j] = false;
                }
            }
            if (dp[i][j]){
                len = gap;
                start = i;
            }
        }
    }
    string ans = "";
    for (int i = start ; i <= len; i++){
        ans += str[i];
    }

    return ans;
}

int main()
{
    string str = "abab";
    // cout << "Enter the string: ";
    // cin >> str;

    cout << longestPalandromicSubstring(str);

    return 0;
}