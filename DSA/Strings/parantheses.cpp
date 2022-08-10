#include <iostream>
#include <stack>
using namespace std;

bool parantheses(string str){
    stack<char> temp;
    for (int i = 0; i < str.length(); i++){
        if (str[i] == '(' || str[i] == '{' || str[i] == '['){
            temp.push(str[i]);
        }
        else if ((temp.top()=='('&& str[i]==')')  ||  (temp.top()=='{' && str[i]=='}')  ||  (temp.top()=='[' && str[i]==']')){
            temp.pop();
        }
    }
    if (temp.empty()){
        return true;
    }
    else{
        return false;
    }

}

int main()
{
    string str;
    cout << "Enter the String: " ;
    cin >> str;

    cout << parantheses(str);

    return 0;
}