// #include <iostream>
// #include <sstream>
// #include <vector>
#include <bits/stdc++.h>
using namespace std;

string removeSpaaces(string str)
{
    stringstream ss;
    string temp; // variable to store each word
    ss << str;   // storing the complete string in ss
    str = "";    // empty the string

    while (!ss.eof())
    {                     // iterating till end of file
        ss >> temp;       // Extracting word by word from stream
        str = str + temp; // Concatenating in the string
    }
    return str;
}

int countWords(string str)
{
    stringstream ss(str);
    string word;

    int count = 0;
    while (ss >> word)
    {
        count++;
    }
    return count;
}

void frequency (string str){
    map <string , int> ans;
    stringstream ss (str);
    string word;

    while (ss >> word){
        ans[word] ++;
    }
    map<string, int>::iterator m;
    for (m = ans.begin(); m != ans.end(); m++)
        cout << m->first << " -> "
             << m->second << "\n";

}

string removeSpaacesG(string str)
{
    stringstream ss;
    string temp; // variable to store each word
    ss << str;   // storing the complete string in ss
    str = "";    // empty the string

    while (getline(ss, temp, ' '))
    {
        str = str + temp;
    }
    return str;
}

int main()
{
    string str = "  Shah  Siddh    Tejaskumar";
    cout << removeSpaaces(str) << endl;
    cout << countWords(str);
}
