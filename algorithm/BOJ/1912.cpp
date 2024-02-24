#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<int> arr(N);
    vector<int> dp(N, 0);
    int maxResult = -1001;
    for (int i = 0; i < N; i++){
        cin >> arr[i];
        if (i >= 1){
            if (dp[i - 1] > 0){
                dp[i] = dp[i - 1] + arr[i];
            }
            else{
                dp[i] = arr[i];
            }
        }
        else{
            dp[0] = arr[i];
        }
        maxResult = max(maxResult, dp[i]);
    }
    cout << maxResult;


    return 0;
}

//     10 -4 3  1  5  6 -35 12 21 -1
// dp  10  6 9 10 15 21 -14 12 33 32