// sliding window concept is used

#include <iostream>
#include <bits/stdc++.h>
#include <map>
using namespace std;

// function to provide the most repeating character count 
int max_count (unordered_map <char, int> count){
    int max = INT_MIN;
    for (auto x : count){
        if (x.second > max){
            max = x.second;
        }
    }
    return max;
}

int character_replacement (string str, int k){
    int start = 0; // start point of window 
    int n = str.length();  int maxLen = 0; // to store the longest possible subbarray length 
    unordered_map <char, int> count;  // to store the count of the alphabets in the CURRENT window

    for (int end = 0; end < n; end++){
        count[str[end]]++;  // adding/populating the count map
        int window_size = end - start + 1;  //window size

        // if in window the no. of different alphabets goes more than k 
        // move window ahead by increasing start value by 1
        if ((window_size - max_count(count)) > k){   
            count[str[start]]--;  // removing the element from map (or decreasing its count)
            start++;   // moving window ahead
        }

        // updating the longest subbarray value 
        maxLen = max(maxLen, end - start + 1);  
    }
    return maxLen;
}


int main()
{
    string str = "hhhhhh";
    
    int replacement;
    cout << "Enter the replacement allowed: ";
    cin >> replacement;

    cout << character_replacement(str, replacement);

    return 0;
}