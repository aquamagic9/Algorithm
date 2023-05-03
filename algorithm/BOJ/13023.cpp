#include <iostream>
#include <vector>
using namespace std;
static vector<vector<int>> nodes;
static vector<bool> visited;
bool arrive = false;

void dfs(int now, int depth){
    if (depth == 5 || arrive){
        arrive = true;
        return;
    }
    visited[now] = true;
    for (int i : nodes[now]){
        if (!visited[i])
            dfs(i, depth + 1);
    }
    visited[now] = false;
}

int main()
{
    int N, M;
    cin >> N >> M;
    visited = vector<bool>(N, false);
    nodes.resize(N);

    for(int i = 0; i < M; i++){
        int s, e;
        cin >> s >> e;
        nodes[s].push_back(e);
        nodes[e].push_back(s);
    }
    for (int i = 0; i < N; i++){
        dfs(i, 1);
        if (arrive)
            break;
    }

    if (arrive)
        cout << 1;
    else
        cout << 0;

    return 0;
}