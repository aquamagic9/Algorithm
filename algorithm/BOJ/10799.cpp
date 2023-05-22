#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string input;
    int cnt = 0, openCnt = 0, ironRodCnt = 0;

    cin >> input;
    stack<char> myStack;
    for (int i = 0; i < input.size(); i++){
        if (input[i] == '('){
            if (i + 1 < input.size() && input[i + 1] == ')')
            {
                cnt += openCnt;
                i = i + 1;
            } else{
                ironRodCnt++;
                openCnt++;
            }
        } else
            openCnt--;
    }
    cout << cnt + ironRodCnt;
    return 0;
}