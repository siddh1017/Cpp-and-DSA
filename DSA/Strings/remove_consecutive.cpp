#include <iostream>
#include <stack>
using namespace std;

// string remove_consecutive(string str){
//     stack <char> temp;
//     temp.push(str[0]);

//     for (int i = 1; i < str.length(); i++){
//         if (str[i] != temp.top()){
//             temp.push(str[i]);
//         }
//     }

//     string ans = "";
//     for (int i = temp.size() - 1; i >=0 ; i--){
//         ans = ans + temp.top();
//         temp.pop();
//     }
//     return ans;
// }

string remove_consecutive(string str){
    string ans = "";

    if (str.length() == 0){
        return ans;
    }

    for (int i = 0; i < str.length() - 1; i++){
        if (str[i] != str[i + 1]){
            ans += str[i];
        }
    }

    ans.push_back(str[str.length() - 1]);
    return ans;
}

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;

    cout << remove_consecutive(str);
    return 0;
}