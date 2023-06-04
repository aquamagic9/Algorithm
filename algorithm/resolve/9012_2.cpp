#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int N;

    cin >> N;
    for (int i = 0; i < N; i++){
        string str;
        cin >> str;
        stack<char> myStack;
        bool VPS = true;
        for (int j = 0; j < str.size(); j++){
            if (str[j] == '('){
                myStack.push('(');
            }
            else if (str[j] == ')'){
                if (myStack.size() != 0 && myStack.top() == '('){
                    myStack.pop();
                }
                else {
                    VPS = false;
                    break;
                }
            }
        }
        if (VPS && myStack.size() == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}