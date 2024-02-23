#include <iostream>
#include <vector>
int dp[1001][2] = {0,};
using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<int> s(N);
    for (int i = 0; i < N; i++){
        cin >> s[i];
    }
    for (int i = 0; i < N; i++){
        int prevMax = 0;
        for (int j = 0; j <= i - 1; j++){
            if (s[i] > s[j])
                prevMax = max(prevMax, dp[j][0]);
        }
        dp[i][0] = prevMax + 1;

        prevMax = 0;
        for (int j = N - i; j < N; j++){
            if (s[N - 1 - i] > s[j])
                prevMax = max(prevMax, dp[j][1]);
        }
        dp[N - 1 - i][1] = prevMax + 1;
    }
    int maxResult = 0;
    for (int i = 0; i < N; i++){
        maxResult = max(dp[i][0] + dp[i][1] - 1, maxResult);
    }
    cout << maxResult;

    return 0;
}

//      10
//      1 5 2 1 4 3 4 5 2 1
//left  1 2 2 1 3 3 4 5 2 1
//right 1 5 2 1 4 3 3 3 2 1
//sum   1 6 3 1 6 5 6 7 3 1