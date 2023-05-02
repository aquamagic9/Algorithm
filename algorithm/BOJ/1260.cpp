#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<int>> nodes;
vector<bool> visited;

void dfs(int id)
{
    cout << id << " ";
    visited[id] = true;
    for (int i : nodes[id]){
        if (!visited[i])
            dfs(i);
    }
}

void bfs(int id)
{
    queue<int> myqueue;
    myqueue.push(id);
    visited[id] = true;

    while (!myqueue.empty()){
        int now = myqueue.front();
        myqueue.pop();
        cout << now << " ";
        for (int i : nodes[now]){
            if (!visited[i]){
                visited[i] = true;
                myqueue.push(i);
            }
        }
    }
}

int main()
{
    int N, M, V;

    cin >> N >> M >> V;
    nodes.resize(N + 1);
    visited.resize(N + 1, false);
    for (int i = 0; i < M; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        nodes[tmp1].push_back(tmp2);
        nodes[tmp2].push_back(tmp1);
    }
    for (int i = 0; i <= N; i++){
        sort(nodes[i].begin(), nodes[i].end());
    }

    dfs(V);
    cout << "\n";
    fill(visited.begin(), visited.end(), false);
    bfs(V);

    return 0;
}