#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// using recursion
int lcs(char *s1, char *s2, int m, int n)
{
    if (m == 0 || n == 0)
    {
        return 0; // if sting gets over
    }
    if (s1[m - 1] == s2[n - 1])
    {
        return 1 + lcs(s1, s2, m - 1, n - 1); // itreating to next value in both the pattern
                                              //(and incrementing the common lenght by 1)
    }
    else
    {
        return max(lcs(s1, s2, m, n - 1), lcs(s1, s2, m - 1, n));   // applying the recusrion call to the both string and 
                                                                    // approving the one which gives max value
    }
}

// using dynamic approcah (to avoid the repeated recursive calls made in above programme)
int lcs(char *X, char *Y, int m, int n,
        vector<vector<int>> &dp)
{
    if (m == 0 || n == 0) // if any of the string gets over
        return 0;
    if (X[m - 1] == Y[n - 1])  // if the string matches then call lcs for next char in both 
        return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);  // increment value 1 and save the value in dynamic 2d array

    if (dp[m][n] != -1)
    {
        return dp[m][n];
    }
    return dp[m][n] = max(lcs(X, Y, m, n - 1, dp), lcs(X, Y, m - 1, n, dp));
}

int main()
{
    char pattern1[] = "AGGTAB";
    char pattern2[] = "GXTXAYB";

    int m = strlen(pattern1);
    int n = strlen(pattern2);
    cout << "Length of LCS using the recursion is " << lcs(pattern1, pattern2, m, n) << endl;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    cout << "Length of LCS using the dynamic programming is " << lcs(pattern1, pattern2, m, n, dp);
    return 0;
}