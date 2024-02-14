#include <iostream>
#include <vector>
using namespace std;
void FindNumberOfCases();
int dp[10001] = {0, };
int main()
{
    int T;

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        FindNumberOfCases();
    }

    return 0;
}

void FindNumberOfCases()
{
    int N, M;

    cin >> N;
    vector<int> coins(N);
    for (int i = 0; i < 10001; i++)
        dp[i] = 0;
    for (int i = 0; i < N; i++)
        cin >> coins[i];
    cin >> M;
    for (int i = 0; i < N; i++)
    {
        int coinValue = coins[i];
        dp[coinValue]++;
        for (int j = coinValue + 1; j <= M; j++)
        {
            if (i == 0 && j % coinValue == 0)
            {
                dp[j] = 1;
                continue;
            }
            dp[j] += dp[j - coinValue];
        }
    }

    cout << dp[M] << '\n';
}

//index : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
//dp 1  : 1 1 1 1 1 1 1 1 1 1  1  1  1  1  1  1  1  1  1  1
//dp 5  : 1 1 1 1 2 2 2 2 2 3  3  3  3  3  4  4  4  4  4  5
//dp 10 : 1 1 1 1 2 2 2 2 2 4  4  4  4  4  6  6  6  6  6  9
//dp[costIndex][i] = dp[costIndex - 1][i] + dp[costIndex][i - costs[costIndex]];

//index : 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22
//dp 5  : 0 0 0 0 1 0 0 0 0 1  0  0  0  0  1  0  0  0  0  1  0  0
//dp 7  : 0 0 0 0 1 0 1 0 0 1  0  1  0  1  1  0  0  0  0  1  1  1