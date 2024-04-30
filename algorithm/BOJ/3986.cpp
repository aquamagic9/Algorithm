#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int cnt = 0, N;

    cin >> N;
    string s;
    for (int i = 0; i < N; i++)
    {
        stack<char> stk;
        cin >> s;
        for (char c : s){
            if (!stk.empty() && c == stk.top()){
                stk.pop();
            }
            else {
                stk.push(c);
            }
        }
        if (stk.empty()){
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}