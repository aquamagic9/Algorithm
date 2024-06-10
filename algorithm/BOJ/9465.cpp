#include <iostream>

using namespace std;
#define MAX 100001

int T, N;
int sticker[2][MAX], dp[2][MAX];

int main() {
    cin >> T;

    for (int testcase = 0; testcase < T; testcase++){
        cin >> N;

        for(int i = 0; i < N; i++)
            cin >> sticker[0][i];
        for(int i = 0; i < N; i++)
            cin >> sticker[1][i];

        for(int i = 0; i < 2; i++)
            dp[i][0]=sticker[i][0];

        dp[0][1] = sticker[0][1]+dp[1][0];
        dp[1][1] = sticker[1][1]+dp[0][0];

        for(int i = 2; i < N; i++) {
            dp[0][i]=sticker[0][i] + max(dp[1][i-1], dp[1][i-2]);
            dp[1][i]=sticker[1][i] + max(dp[0][i-1], dp[0][i-2]);
        }
        cout << max(dp[0][N-1], dp[1][N-1]) << "\n";
    }
}