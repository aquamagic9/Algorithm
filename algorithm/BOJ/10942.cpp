#include <iostream>
#include <vector>
using namespace std;

int n, m;
int dp[2001][2001];

bool check(int j, int i)
{
    while (i >= 1 && j >= 1 && j <= n){
        if (dp[j][i] != 1)
            return false;
        i -= 2;
        j += 1;
    }
    return true;
}
int main()
{
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n - i + 1; j++){
            if (v[j] == v[j + i - 1] && check(j + 1, i - 2)){
                dp[j][i] = 1;
            }
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        cout << dp[s][e - s + 1] << "\n";
    }

    return 0;
}