#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> &nodes, int id, vector<pair<int, int>> &edges){
    if (nodes[id] == 1)
        return;
    nodes[id] = 1;
    for (pair<int, int> edge : edges){
        if (edge.first == id)
            dfs(nodes, edge.second, edges);
        else if (edge.second == id)
            dfs(nodes, edge.first, edges);
    }
}

int main()
{
    int N, E;

    cin >> N >> E;
    vector<int> nodes(N + 1, 0);
    vector<pair<int, int>> edges;
    for (int i = 0; i < E; i++){
        pair<int, int> tmp;
        cin >> tmp.first >> tmp.second;
        edges.push_back(tmp);
    }
    int cnt = 0;
    for (int i = 1; i <= N; i++){
        if (nodes[i] == 0){
            cnt++;
            dfs(nodes, i, edges);
        }
    }
    cout << cnt << "\n";

    return 0;
}
