#include <iostream>
using namespace std;

bool palindrome (string str){
    int l = 0, h = str.length() - 1;
    for (int i = 0 ; i < str.length(); i++){
        str[i] = tolower(str[i]);
    }

    while (l <= h){
        if (!(str[l] >= 'a' && str[l] <= 'z')){
            l++;
        }
        else if (!(str[h] >= 'a' && str[h] <= 'z')){
            h--;
        }
        else if (str[l] == str[h]){
            l++; h--;
        } 
        else{
            return false;
        }
    }
    return true;
}


int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;

    cout << palindrome(str);
    return 0;
}