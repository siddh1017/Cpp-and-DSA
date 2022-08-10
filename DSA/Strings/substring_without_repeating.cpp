// Sliding Window concept (usefull)

#include <iostream>
#include <vector>
using namespace std;

// // WINDOW method O(n^2)
// int longestSubstring(string str){
//     int n = str.size(); int ans = 0;

//     for (int i = 0; i < n; i++){
//         vector<bool> visited(256);
//         for (int j = i; j < n ; j++){
//             if (visited[str[j]]){   // if the letter is visited 
//                 break;
//             }
//             else{
//                 ans = max (ans, j - i + 1);  // selecting the max size ( j-i+1  is the size of the current window whichh changes as j)
//                 visited[str[i]] = true;   
//             }
//         }
//         visited[str[i]] = false;  // removing the first charater of window 
//     }
//     return ans;
// }

// O(n)
int longestSubstring (string str){
    int n = str.length(); int ans = 0;  // to store the max length

    int start = 0;  // start index to iterate the string 

    vector<int> last_occurence (256, -1);  
    // vector to store the last occurrence of each element
    // it is updated as the repeatation occurr 
    // initialized as -1 for every letter

    for (int end = 0; end < n; end++){

        // start will be updated if the element is repeated and we can see that in last_occurence vector 
        // start will jump to that repeated index 
        start = max (start, last_occurence[str[end]] + 1);

        // ans will be updated if the current window size (end - start + 1) is larger than previous  
        ans = max(ans, end - start + 1);

        // adding/updating the last_occurrence vector as the each element is visited  
        last_occurence[str[end]] = end;
    }
    return ans;
}

int main()
{
    string str;
    cout << "Enter string: ";
    cin >> str;

    cout << longestSubstring(str); 
    return 0;
}