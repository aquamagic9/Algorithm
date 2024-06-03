#include <iostream>
using namespace std;

const int Div = 1000000000;
int dp[10][101][1024];
int n;

int go(int num, int digit, int bits)
{
    if (dp[num][digit][bits] != 0){
        return dp[num][digit][bits];
    }
    if (digit == n){
        if (bits == 1023){
            return 1;
        }
        return 0;
    }
    int cnt = 0;
    if (num - 1 >= 0){
        cnt += go(num - 1, digit + 1, bits | (1 << (num - 1)));
    }
    if (num + 1 <= 9){
        cnt += go(num + 1, digit + 1, bits | (1 << (num + 1)));
    }
    cnt %= Div;
    dp[num][digit][bits] = cnt;
    return cnt;
}

int main()
{
    cin >> n;
    int answer = 0;
    for (int i = 1; i <= 9; i++){
        answer += go(i, 1, 1 << i);
        answer %= Div;
    }
    cout << answer;

    return 0;
}