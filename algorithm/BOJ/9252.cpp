#include <iostream>
#include <cstring>
using namespace std;

int dp[1001][1001];
string s1, s2;
void printStr()
{
    int x = s2.size();
    int y = s1.size();
    string result = "";
    while (!(x < 1 || y < 1)){
        if (dp[y][x] != dp[y][x - 1] && dp[y][x] != dp[y - 1][x])
        {
            result = s2[x - 1] + result;
            x--;
            y--;
        }
        else if (dp[y][x - 1] > dp[y - 1][x]){
            x--;
        }
        else{
            y--;
        }
    }
    if (!result.empty())
        cout << "\n" << result;
}
int main()
{

    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++){
        for (int j = 0; j < s2.size(); j++){
            if (s1[i] == s2[j]){
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else{
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }

    cout << dp[s1.size()][s2.size()];
    printStr();

    return 0;
}