#include <iostream>
using namespace std;

int n;
int cost[1001][3];
const int MaxInt = 1000 * 1000 + 1;
int main()
{
    int answer = MaxInt;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int r, g, b;
        cin >> r >> g >> b;
        cost[i][0] = r;
        cost[i][1] = g;
        cost[i][2] = b;
    }

    for (int start = 0; start <= 2; start++){
        int dp[1001][3];
        for (int color = 0; color <= 2; color++){
            if (start == color){
                dp[1][color] = cost[1][color];
            }
            else{
                dp[1][color] = MaxInt;
            }
        }
        for (int i = 2; i <= n; i++) {
            dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
            dp[i][1] = cost[i][1] + min(dp[i - 1][2], dp[i - 1][0]);
            dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
        }
        for (int color = 0; color <= 2; color++){
            if (start == color)
                continue;
            answer = min(answer, dp[n][color]);
        }
    }

    cout << answer;

    return 0;
}