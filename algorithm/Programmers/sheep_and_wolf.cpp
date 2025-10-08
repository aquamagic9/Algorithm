#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Node{
    int sheepCnt;
    int wolfCnt;
};

bool isEmptyNode(Node node){
    return node.sheepCnt == 0 && node.wolfCnt == 0;
}

void calculateDP(vector<vector<Node>> &dp, int c, int v, map<int, vector<int>> &mEdge, vector<int> &info, int &maxSCnt, int &maxWCnt){
    maxSCnt = max(maxSCnt, dp[c][v].sheepCnt);
    maxWCnt = max(maxWCnt, dp[c][v].wolfCnt);
    //cout << c << " " << v << " " << dp[c][v].sheepCnt << " " << dp[c][v].wolfCnt<< endl;

    for (int next : mEdge[c]){
        if (!isEmptyNode(dp[next][v | 1 << next])
            || info[next] && dp[c][v].sheepCnt <= dp[c][v].wolfCnt + 1)
            continue;
        dp[next][v | 1 << next] = dp[c][v];
        if (!(v & 1 << next))
            info[next] ? dp[next][v | 1 << next].wolfCnt++ : dp[next][v | 1 << next].sheepCnt++;
        calculateDP(dp, next, v | 1 << next, mEdge, info, maxSCnt, maxWCnt);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 1;

    map<int, vector<int>> mEdge;
    for (auto edge : edges){
        mEdge[edge[0]].push_back(edge[1]);
        mEdge[edge[1]].push_back(edge[0]);
    }

    Node tmp;
    tmp.sheepCnt = 0; tmp.wolfCnt = 0;
    vector<Node> row(1 << (info.size() + 2), tmp);
    vector<vector<Node>> dp(info.size(), row);

    dp[0][1].sheepCnt = 1 << 0;
    int maxSCnt = 0, maxWCnt = 0;
    calculateDP(dp, 0, 1 << 0, mEdge, info, maxSCnt, maxWCnt);
    answer = maxSCnt;

    return answer;
}

int main()
{
//    vector<int> info = {0,0,1,1,1,0,1,0,1,0,1,1};
//    vector<vector<int>> edges = {{0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}};
    vector<int> info = {0,1,0,1,1,0,1,0,0,1,0};
    vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6},{3,7},{4,8},{6,9},{9,10}};

    cout << solution(info, edges);

    return 0;
}