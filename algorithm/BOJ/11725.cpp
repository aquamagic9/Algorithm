#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> graph[100001];
int parent[100001] = {0,};

void dfs(int node)
{
    for (int i = 0; i < graph[node].size(); i++){
        if (parent[graph[node][i]] == 0){
            parent[graph[node][i]] = node;
            dfs(graph[node][i]);
        }
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N - 1; i++){
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    dfs(1);
    for (int i = 2; i <= N; i++){
        cout << parent[i] << "\n";
    }

    return 0;
}