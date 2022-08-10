#include <iostream>
#include <vector>
using namespace std;

// finding the value of strings 
int find_sum(string str){
    int sum = 0;
    for (int i = 0; i < str.length(); i++){
        sum += str[i] - 'a' + 1;
    }
    return sum;
}

// using insertion sort 
void Algorithm (vector<pair<string, int>> &words){
    int temp, j;
    string str;
    for (int i = 1; i < words.size(); i++){
        temp = words[i].second;
        str = words[i].first;
        j = i - 1;
        while (j >= 0 && words[j].second > temp){
            words[j + 1] = words[j];
            j--; 
        }
        words[j + 1].second = temp;
        words[j + 1].first = str;
    }
}

// printing the pairs
void print (vector<pair <string, int>> str){
    for (int i = 0; i < str.size(); i++){
        cout << "(" << str[i].first << ", " << str[i].second << ") "; 
    }
}

int main()
{
    int n;
    cout << "Enter the no. of words: ";
    cin >> n;

    vector<pair<string, int>> words;
    string word; int value;

    cout << "Enter the words" << endl;
    for (int i = 0; i < n; i++){
        cin >> word;
        value = find_sum(word);
        words.push_back(make_pair(word, value)); 
    }
    Algorithm(words);
    print(words);
    return 0;
}