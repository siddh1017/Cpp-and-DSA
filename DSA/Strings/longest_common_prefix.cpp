#include <iostream>
#include <string>
using namespace std;

// function to find min Length word
int minLenght(string str[], int n){
    int min = str[0].length();
    for (int i = 1; i < n; i++){
        if (str[i].length() < min){
            min = str[i].length();
        }
    }
    return min;
}


string commonPrefix(string str[], int n){
    int minLen = minLenght(str, n);   // finding word with min length
    string ans; char current;

    for (int i = 0; i < minLen; i++){
        current = str[0][i]; // stores the current character of 1st word 

        for (int j = 1; j < n; j++){
            if (str[j][i] != current){   // if the current char mismatches with another char return ans
                return ans;
            }
        }
        ans.push_back(current); // if all the charcter matches 
    }
    return ans;
}


int main()
{
    int n; 
    cout << "Enter no. of string: ";
    cin >> n;

    string str[n];
    for (int i = 0; i < n; i++){
        cin >> str[i];
    }

    cout << commonPrefix(str, n);
    
    return 0;
}