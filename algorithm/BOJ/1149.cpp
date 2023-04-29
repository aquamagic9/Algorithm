#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<vector<int>> dp(N + 1);
    vector<vector<int>> rgb(N + 1);
    for (int i = 0; i < N + 1; i++)
    {
        dp[i].resize(3, 0);
        rgb[i].resize(3, 0);
    }

    for(int i = 1; i < N + 1; i++) {
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + rgb[i][0];
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + rgb[i][1];
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + rgb[i][2];
    }

    cout << min(min(dp[N][0], dp[N][1]), dp[N][2]);

    return 0;
}