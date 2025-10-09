#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

#define INF 100000000

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second < b.second;
    }
};

void dijkstra(vector<int> &minVec, int start, int n, vector<vector<int>> &graph){
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    pq.push({start, 0});
    minVec[start] = 0;
    while(!pq.empty()){
        pair<int, int> edge = pq.top(); pq.pop();
        int num = edge.first;
        int weight = edge.second;
        for (int i = 1; i <= n; i++){
            if (graph[num][i] == 0)
                continue;
            if (minVec[i] > minVec[num] + graph[num][i]){
                minVec[i] = minVec[num] + graph[num][i];
                pq.push({i, minVec[i]});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<int> row(n + 1, 0);
    vector<vector<int>> graph(n + 1, row);
    for (vector<int> &fare : fares){
        graph[fare[0]][fare[1]] = fare[2];
        graph[fare[1]][fare[0]] = fare[2];
    }

    vector<int> startVec(n + 1, INF);
    dijkstra(startVec, s, n, graph);

    vector<int> aVec(n + 1, INF);
    dijkstra(aVec, a, n, graph);

    vector<int> bVec(n + 1, INF);
    dijkstra(bVec, b, n, graph);

    for (int i = 1; i <= n; i++){
        if (answer > aVec[i] + bVec[i] + startVec[i]){
            answer = aVec[i] + bVec[i] + startVec[i];
        }
    }

    return answer;
}

int main()
{
    int n = 6, s = 4, a = 6, b = 2;
    vector<vector<int>> fares = {{4, 1, 10}, {3, 5, 24}, {5, 6, 2}, {3, 1, 41}, {5, 1, 24}, {4, 6, 50}, {2, 4, 66}, {2, 3, 22}, {1, 6, 25}};

    cout << solution(n, s, a, b, fares);

    return 0;
}