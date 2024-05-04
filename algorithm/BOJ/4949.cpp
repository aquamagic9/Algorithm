#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<char> parentheses;

bool isParentheses(char c){
    for (char p : parentheses){
        if (p == c){
            return true;
        }
    }
    return false;
}

bool isBalance(char openP, char closeP){
    for (int i = 0; i < parentheses.size(); i += 2){
        if (openP == parentheses[i] && closeP == parentheses[i + 1]){
            return true;
        }
    }
    return false;
}

int main(){
    string s;
    parentheses.push_back('(');
    parentheses.push_back(')');
    parentheses.push_back('[');
    parentheses.push_back(']');

    while (getline(cin, s)){
        stack<int> stk;
        if (s == ".")
            break;
        for (int i = 0; i < s.length(); i++){
            if (isParentheses(s[i])){
                if(!stk.empty() && isBalance(stk.top(), s[i])) {
                    stk.pop();
                }
                else{
                    stk.push(s[i]);
                }
            }
        }
        if (stk.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}