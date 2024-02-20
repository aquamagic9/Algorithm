#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;

int CalculateString(string s)
{
    int result = 0;
    int num = 0;
    int sign = 1;
    for (int i = 0; i < s.length(); i++){
        if (s[i] >= '0' && s[i] <= '9'){
            num += sign * (s[i] - '0');
        }
        else{
            if (s[i] == ' '){
                num = num * 10;
            }
            else if (s[i] == '+'){
                result += num;
                num = 0;
                sign = 1;
            }
            else if (s[i] == '-'){
                result += num;
                num = 0;
                sign = -1;
            }
        }
    }
    result += num;

    return result;
}

void solution(int num, string s)
{
    if (num == N)
    {
        if (CalculateString(s) == 0)
            cout << s << "\n";
        return;
    }
    num++;
    solution(num, s + ' ' + to_string(num));
    solution(num, s + '+' + to_string(num));
    solution(num, s + '-' + to_string(num));
}

int main()
{
    int testcase;

    cin >> testcase;
    for (int i = 1; i <= testcase; i++){
        cin >> N;
        string s = "1";
        solution(1, s);
        cout << "\n";
    }

    return 0;
}