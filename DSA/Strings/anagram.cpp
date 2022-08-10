#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool anagram (string str1, string str2){
    if (str1.length() != str2.length()){
        return false;
    }
    sort (str1.begin(), str1.end());
    sort (str2.begin(), str2.end());

    for (int i = 0; i < str1.length(); i++){
        if (str1[i] != str2[i]){
            return false;
        }
    }
    return true;
}

int main()
{
    string str1, str2;
    cout << "Enter the string1 : ";
    cin >> str1;
    cout << "Enter the string2 : ";
    cin >> str2;

    cout  << anagram(str1, str2);
    return 0;
}