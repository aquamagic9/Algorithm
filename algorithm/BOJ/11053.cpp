#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<int> dp(N, 1);
    vector<int> seq(N);
    for (int i = 0; i < N; i++){
        cin >> seq[i];
    }
    for (int i = 0; i < N; i++){
        for (int j = i; j < N; j++){
            if (seq[i] < seq[j] && dp[i] >= dp[j]){
                dp[j] = dp[i] + 1;
            }
        }
    }
    int maxValue = 0;
    for (int i = 0; i < N; i++){
        if (maxValue < dp[i])
            maxValue = dp[i];
    }
    cout << maxValue;

    return 0;
}