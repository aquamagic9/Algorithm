#include <iostream>
#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<int> row(n, 0);
    vector<vector<int>> dp(m, row);

    for (int x = 0; x < n; x++){
        if (city_map[0][x] == 1)
            break;
        if (city_map[0][x] == 2)
            continue;
        dp[0][x] = 1;
    }
    for (int y = 1; y < m; y++){
        for (int x = 0; x < n; x++){
            int sumX = 0, sumY = 0;
            if (city_map[y][x] == 0){
                int dx = x - 1, dy = y - 1;
                while (dx >= 0 && city_map[y][dx] != 1){
                    if (city_map[y][dx] == 0){
                        sumX = dp[y][dx];
                        break;
                    }
                    dx--;
                }
                while (dy >= 0 && city_map[dy][x] != 1){
                    if (city_map[dy][x] == 0){
                        sumY = dp[dy][x];
                        break;
                    }
                    dy--;
                }
                dp[y][x] = sumX + sumY;
                if (dp[y][x] > MOD)
                    dp[y][x] %= MOD;
            }
        }
    }
    answer = dp[m - 1][n - 1];

    return answer;
}

int main()
{
    int m = 3, n = 3;
    vector<vector<int>> city_map = {{0,0,0},{0,0,0},{0,0,0}};
    int m2 = 3, n2 = 6;
    vector<vector<int>> city_map2 = {{0,2,0,0,0,2},{0,0,2,0,1,0},{1,0,0,2,2,0}};

    cout << solution(m2, n2, city_map2) << endl;

    return 0;
}