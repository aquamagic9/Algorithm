#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int T, N;

    cin >> T;
    for (int i = 0; i < T; i++){
        cin >> N;
        vector<int> dp(N + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int j = 4; j <= N; j++){
            dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
        }
        cout << dp[N] << "\n";
    }

    return 0;
}
//dp  1  2  3  4  5  6  7  8  9  10  11
//s   1  2  4  7  13
// dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
