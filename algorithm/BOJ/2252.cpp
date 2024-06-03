#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int degree[32001];
vector<int> v[32001];

void topologySort() {
    int result[n + 1];
    queue<int> q;

    for (int i = 1; i <= n; i++){
        if (degree[i] == 0){
            q.push(i);
        }
    }

    for (int i = 1; i <= n; i++){
        if (q.empty()){
            return;
        }
        int x = q.front();
        q.pop();
        result[i] = x;
        for (int j = 0; j < v[x].size(); j++){
            int nextNode = v[x][j];
            if (--degree[nextNode] == 0){
                q.push(nextNode);
            }
        }
    }
    for (int i = 1; i <= n; i++){
        cout << result[i] << " ";
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int start, end;
        cin >> start >> end;
        v[start].push_back(end);
        degree[end]++;
    }
    topologySort();

    return 0;
}