#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int n;
float weightSum = 0;
float visit[101];
vector<pair<int, float>> v[101];

float inline findCost(pair<float, float> a, pair<float, float> b)
{
    return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

struct compare{
    bool operator()(pair<int, float> a, pair<int, float> b)
    {
        return a.second > b.second;
    }
};

void prim(int node){
    priority_queue<pair<int, float>, vector<pair<int, float>>, compare> pq;

    for (int i = 0; i < v[node].size(); i++){
        pq.push(v[node][i]);
    }
    visit[node] = 1;

    int cnt = 0;
    while (cnt < n - 1)
    {
        int startNode = pq.top().first;
        float cost = pq.top().second;
        pq.pop();

        if (visit[startNode] == 1)
            continue;
        visit[startNode] = 1;
        weightSum += cost;
        cnt++;
        for (int i = 0; i < v[startNode].size(); i++){
            int nextNode = v[startNode][i].first;
            if (visit[nextNode] == 0){
                pq.push(v[startNode][i]);
            }
        }
    }
}
int main()
{
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
    prim(0);
    
    cout.precision(3);
    cout << weightSum;

    return 0;
}