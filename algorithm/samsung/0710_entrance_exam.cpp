#include <iostream>
#include <vector>
#define MAX 2147483647
using namespace std;
struct Edge{
    int nextNode;
    int cost;
};
vector<bool> discovered, finished;
vector<vector<Edge>> adj;
int minCost = MAX;

void dfs(int node, int cost)
{
    discovered[node] = true;

    for(Edge edge : adj[node]) {
        int next = edge.nextNode;

        if (discovered[next] == false) {
            dfs(next, (cost + edge.cost));
        }
        else if (finished[next] == false) {
            if (minCost > (cost + edge.cost)){
                minCost = (cost + edge.cost);
                //cout << node << " -> " << next << "(" << minCost  << ")" << endl;
            }
        }
    }
    finished[node] = true;
}
int main()
{
    int T, N, M;

    cin >> T;
    for (int i = 0; i < T; i++){
        minCost = MAX;
        cin >> N >> M;
        vector<vector<Edge>> adjs(N + 1);
        adj = adjs;
        for (int j = 0; j < M; j++){
            int X, Y, C;
            Edge tmp;
            cin >> X >> Y >> C;
            tmp.nextNode = Y;
            tmp.cost = C;
            adj[X].push_back(tmp);
            for (Edge edge : adj[Y]){
                if (edge.nextNode == X){
                    if (minCost > (edge.cost + tmp.cost))
                        minCost = (edge.cost + tmp.cost);
                }
            }
        }
        for (int j = 1; j < N + 1; j++){
            vector<bool> a(N + 1, false);
            vector<bool> b(N + 1, false);
            discovered = a;
            finished = b;
            dfs(j, 0);
        }
        if (minCost == MAX)
            minCost = -1;
        cout << "#" << i + 1 << " " << minCost << "\n";
    }

    return 0;
}