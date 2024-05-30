#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int visitCost[1003];
vector<pair<int, int>> v[1003];

void dijkstra(int node){
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;

    pq.push(make_pair(node, 0));
    visitCost[node] = 0;
    while (!pq.empty())
    {
        int startNode = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if (visitCost[startNode] < cost)
            continue;

        for (int i = 0; i < v[startNode].size(); i++){
            int nextNode = v[startNode][i].first;
            int nextCost = cost + v[startNode][i].second;
            if (visitCost[nextNode] > nextCost){
                pq.push(make_pair(nextNode, nextCost));
                visitCost[nextNode] = nextCost;
            }
        }
    }
}
int main(){
    int n, m;
    cin >> n >> m;

    v[0].push_back(make_pair(0, 0));
    fill(visitCost, &visitCost[1002], 2147483647);
    for (int i = 0; i < m; i++){
        int s, e, c;
        cin >> s >> e >> c;
        v[s].push_back(make_pair(e, c));
    }
    int st, dt;
    cin >> st >> dt;
    dijkstra(st);
    cout << visitCost[dt];

    return 0;
}