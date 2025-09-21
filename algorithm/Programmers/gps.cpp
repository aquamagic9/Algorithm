#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 101
using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;
    map<int, vector<int>> map;

    for (auto v : edge_list){
        map[v[0]].push_back(v[1]);
        map[v[1]].push_back(v[0]);
    }

    vector<int> v(n + 1, MAX);
    vector<vector<int>> dp(k, v);

    dp[0][gps_log[0]] = 0;
    for (int i = 1; i < k; i++){
        for (int j = 1; j < n + 1; j++){
            dp[i][j] = min(dp[i - 1][j], dp[i][j]);
            for (int node : map[j]){
                dp[i][j] = min(dp[i - 1][node], dp[i][j]);
            }
            dp[i][j] += gps_log[i] == j ? 0 : 1;
        }
    }

    if (dp[k - 1][gps_log[k - 1]] == MAX)
        answer = -1;
    else
        answer = dp[k - 1][gps_log[k - 1]];

    return answer;
}

int main()
{
    int n = 7, m = 10, k = 6;
    vector<vector<int>> edge_list = {{1,2},{1,3},{2,3},{2,4},{3,4},{3,5},{4,6},{5,6},{5,7},{6,7}};
    vector<int> gps_log = {1,2,3,3,6,7};
    int answer = 0;

    answer = solution(n, m, edge_list, k, gps_log);

    cout << answer << endl;

    return 0;
}