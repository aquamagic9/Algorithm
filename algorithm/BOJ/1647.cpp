#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

vector<pair<int, int>> v[100001];
int visit[100001];
int n, m, weightSum = 0;
void prim(int node){
    priority_queue<pair<int, float>, vector<pair<int, float>>, compare> pq;
    int maxCost = 0;
    for (int i = 0; i < v[node].size(); i++){
        pq.push(v[node][i]);
    }
    visit[node] = 1;

    int cnt = 0;
    while (cnt < n - 1)
    {
        int startNode = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if (visit[startNode] == 1)
            continue;
        visit[startNode] = 1;
        weightSum += cost;
        if (maxCost < cost){
            maxCost = cost;
        }
        cnt++;
        for (int i = 0; i < v[startNode].size(); i++){
            int nextNode = v[startNode][i].first;
            if (visit[nextNode] == 0){
                pq.push(v[startNode][i]);
            }
        }
    }
    weightSum -= maxCost;
}
int main()
{
    cin >> n >> m;
    int firstNode, minCost = 1001;
    for (int i = 0; i < m; i++){
        int sn, en, cost;
        cin >> sn >> en >> cost;
        if (minCost > cost){
            firstNode = sn;
            minCost = cost;
        }
        v[sn].push_back({en, cost});
        v[en].push_back({sn, cost});
    }
    prim(firstNode);
    cout << weightSum;

    return 0;
}