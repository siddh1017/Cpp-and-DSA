#include <iostream>
#include <math.h>
using namespace std;

void naive_algorithm (string text , string pattern){    
    int n = text.length(); int m= pattern.length();
    for (int i=0 ; i<n; i++){
        for (int j=0; j<m ; j++){
            if (text[i+j] != pattern[j]){  // if at any point character dont match 
                break;
            }
            if (j == m-1){  // means the strings matched completely
                cout << "pattern found at index: " << i << endl;
            }
        }
    }
}
 
int value (char c){   // assigning the a=1, b=2 , and so on
    return c-'a'+1;
}

// can be used only for smaller pattern size 
void rabin_karp (string text, string pattern){
    int n = text.length(); int m = pattern.length();
    int prime = 5381;  // taking higher prime no., to avoid the spurious hits
    int hash_text = 0, t = 0;  // hash value for the text
    int hash_pattern = 0;  // hash value for the pattern 
    int allow = 26; // only alphabets

    // calculating the  hash value for first window of text and pattern 
    for (int i=0; i<m; i++){
        hash_pattern = hash_pattern + (value(pattern[i])*pow(allow, m-i-1));
        hash_text = hash_text + (value(text[i])*pow(allow, m-i-1));
    }

    // taking modulous to avoid the spurious hits
    hash_pattern = hash_pattern%prime;  
    t = hash_text%prime;   
    

    for (int i=0; i<n; i++){
        if (hash_pattern == t){  // if hash value matches 
            for (int j=0; j<m; j++){  // checking if text matches or not 
                if (pattern[j] != text[i+j]){  
                    break;
                }
                else if (j == m-1){
                    cout << "Found at position at: " << i << endl;
                }
            }
        }
        if (i < n-m){  // if not then roll the hash function
            hash_text =  (hash_text - value(text[i])*pow(allow, m-1))*allow + value(text[m+i]); 
            t = hash_text%prime;
        }
    }
}

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    cin >> text;
    cout << "ENter the Pattern : ";
    cin >> pattern;

    if (pattern.length() > text.length()){
        cout << "Invalid Input" << endl;
    }
    else {
        cout << "Using the Naive Algorithm: " << endl;
        naive_algorithm(text, pattern);
        cout << "Using the Rabin karp Algorithm: " << endl;
        rabin_karp(text, pattern);
    }
    return 0;
}

