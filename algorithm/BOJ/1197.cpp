#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int v, e, weightSum = 0;
int visit[10001];
vector<pair<int, int>> vertex[10001];

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

void prim()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for (int i = 0; i < vertex[1].size(); i++){
        pq.push(vertex[1][i]);
    }
    visit[1] = 1;
    int cnt = 0;
    while (cnt < v - 1){
        int nextNode = pq.top().first;
        int weight = pq.top().second;
        pq.pop();
        if (visit[nextNode] == 1){
            continue;
        }
        visit[nextNode] = 1;
        weightSum += weight;
        cnt++;
        for (int i = 0; i < vertex[nextNode].size(); i++){
            if (visit[vertex[nextNode][i].first] == 0){
                pq.push(vertex[nextNode][i]);
            }
        }
    }
}

int main()
{
    cin >> v >> e;
    for (int i = 0; i < e; i++){
        int start, end, weight;
        cin >> start >> end >> weight;
        vertex[start].push_back({end, weight});
        vertex[end].push_back({start, weight});
    }
    prim();
    cout << weightSum;

    return 0;
}