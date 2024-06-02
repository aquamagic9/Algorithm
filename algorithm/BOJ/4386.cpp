#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

float visitCost[101];
vector<pair<int, float>> v[101];

float inline findCost(pair<float, float> a, pair<float, float> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

void dijkstra(int node){
    priority_queue<pair<int, float>, vector<pair<int, float>>, greater<pair<int, float>>> pq;

    pq.push(make_pair(node, 0));
    visitCost[node] = 0;
    while (!pq.empty())
    {
        int startNode = pq.top().first;
        float cost = pq.top().second;
        pq.pop();

        if (visitCost[startNode] < cost)
            continue;

        for (int i = 0; i < v[startNode].size(); i++){
            int nextNode = v[startNode][i].first;
            float nextCost = cost + v[startNode][i].second;
            if (visitCost[nextNode] > nextCost){
                pq.push(make_pair(nextNode, nextCost));
                visitCost[nextNode] = nextCost;
            }
        }
    }
}
int main()
{
    int n;

    cin >> n;
    vector<pair<float, float>> pos;
    for (int i = 0; i < n ; i++){
        float a, b;
        cin >> a >> b;
        pos.push_back({a, b});
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j)
                continue;
            v[i].push_back({j, findCost(pos[i], pos[j])});
        }
    }
    fill(visitCost, &visitCost[101], 100000);
    dijkstra(0);
    
    cout.precision(3);
    cout << visitCost[n - 1];

    return 0;
}