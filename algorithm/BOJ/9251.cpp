#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2;
    int dp[1001] = {0, };

    cin >> s1 >> s2;
    for (int i = 0; i < s2.length(); i++){
        int prev = 0;
        for (int j = 0; j < s1.length(); j++){
            if (s1[j] == s2[i]){
                int oldValue = dp[j];
                dp[j] = prev + 1;
                prev = oldValue;
            }
            else{
                prev = dp[j];
                dp[j] = max(dp[j], (j - 1) >= 0 ? dp[j - 1] : 0);
            }
        }
    }
    cout << dp[s1.length() - 1];

    return 0;
}

//   A C A Y K P
// C 0 1 1 1 1 1
// A 1 1 2 2 2 2
// P 1 1 2 2 2 3
// C 1 2 2 2 2 3
// A 1 2 3 3 3 3
// K 1 2 3 3 4 4

//   K K K B C B C A K
// K 1 1 1 1 1 1 1 1 1
// C 1 1 1 1 2 2 2 2 2
// K 1 2 2 2 2 2 2 2 3
// B 1 2 2 3 3 3 3 3 3
// C 1 2 2 3 4 4 4 4 4
// B 1 2 2 3 4 5 5 5 5
// C 1 2 2 3 4 5 6 6 6
// A 1 2 2 3 4 5 6 7 7
// A 1 2 2 3 4 5 6 7 7