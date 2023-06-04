#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int N;

    cin >> N;
    for (int i = 0; i < N; i++){
        stack<char> myStack;
        string PS;
        cin >> PS;
        bool isVPS = true;
        for (int j = 0; j < PS.size(); j++){
            if (PS[j] == '(')
                myStack.push(PS[j]);
            else if (PS[j] == ')'){
                if (myStack.size() != 0 && myStack.top() == '(')
                    myStack.pop();
                else{
                    isVPS = false;
                    break;
                }
            }
        }
        if (isVPS && myStack.size() == 0)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}