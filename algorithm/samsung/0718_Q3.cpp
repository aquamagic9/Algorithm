#include <iostream>
#include <cstring>
using namespace std;
long long dp[16][10000];

int main()
{
    int T;

    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++){
        string str;
        memset(dp, 0, sizeof(dp));
        cin >> str;
        for (int i = 0; i < str.size(); i++){
            int mask = (1 << (str[i] - 'A'));
            if (i == 0){
                mask |= 1;
                for (int curr = 1; curr < 16; curr++){
                    if ((curr & mask) == mask){
                        dp[curr][i] = 1;
                    }
                }
            }else{
                for (int prev = 1; prev < 16; prev++){
                    if (dp[prev][i - 1]){
                        for (int curr = 1; curr < 16; curr++){
                            if ((prev & curr) && (curr & mask))
                                dp[curr][i] = (dp[prev][i - 1] + dp[curr][i]) % 1000000007;;
                        }
                    }
                }
            }
        }
        int sum = 0;
        for (int i = 1; i < 16; i++){
            sum = (sum + dp[i][str.size() - 1]) % 1000000007;
        }
        cout << "#" << test_case << " " << sum << "\n";
    }
    return 0;
}
