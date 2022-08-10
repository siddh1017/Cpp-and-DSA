#include <bits/stdc++.h>
#include <iostream>
using namespace std;
void computeLPSArray(char* pat, int m, int* lps);

void KmPSearch(char* pat, char* txt)
{
	int m = strlen(pat);
	int n = strlen(txt);

	// lps array to hold the longest suffix and prefix 
	int lps[m];
	computeLPSArray(pat, m, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while (i < n) {
		if (pat[j] == txt[i]) {  // if text matches then continue to next index
			j++;
			i++;
		}

		if (j == m) {  // means that we found the pattern 
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];  
		}

        // if at any point the mismatch occurs
		else if (i < n && pat[j] != txt[i]) {
			if (j != 0)  // if the j != 0, then
                         // go to the corresponding pie value in from lps check from that value
				j = lps[j - 1];
			else  // if we are already at index 0 of pattern then move ahead in text
				i = i + 1;
		}
	}
}

// to calculte the pie table of the pattern
void computeLPSArray(char* pat, int m, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;  // the index we are supposed to jump

	lps[0] = 0; // lps[0] is always 0
	int i = 1;
	while (i < m) {
		if (pat[i] == pat[len]) {  // if the charcter matches 
			len++;    // increment the length 
			lps[i] = len;   // allocate the value in pie table
			i++;  // move to next value
		}
		else // (pat[i] != pat[len])
		{
			if (len != 0) {   // case: ABABC if we are at C 
				len = lps[len - 1];
			}
			else // if we are at index 0 or when len is reduced to value 0
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main()
{
    int n, m;
    cout << "Enter the text length: ";
    cin >> n;
    char txt[n];
    cout << "Enter the text: ";
    for (int i=0; i<n ;i++){
        cin >> txt[i];
    }
    cout << "Enter the pattern length: ";
    cin >> m;
    char pat[m];
    cout  << "Enter the pattern: ";
    for (int i=0; i<m ;i++){
        cin >> pat[i];
    }

    if (n < m){
        cout << "Invalid input";
    }
    else{
        KmPSearch(pat, txt);
    }
	return 0;
}
