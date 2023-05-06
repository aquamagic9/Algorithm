#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<bool> visited;
vector<int> dist;

void bfs(int start, vector<vector<pair<int,int>>> &nodes)
{
    queue<int> my_queue;
    my_queue.push(start);
    visited[start] = true;
    while(!my_queue.empty()){
        int id = my_queue.front();
        my_queue.pop();
        for (pair<int, int> i : nodes[id]){
            if (visited[i.first] == false)
            {
                my_queue.push(i.first);
                visited[i.first] = true;
                dist[i.first] = dist[id] + i.second;
            }
        }
    }
}

int findMaxDistanceIndex()
{
    int max = 1;
    for (int i = 1; i < dist.size(); i++){
        if (dist[max] < dist[i]){
            max = i;
        }
    }
    return max;
}

int main()
{
    int N;

    cin >> N;
    vector<vector<pair<int,int>>> nodes(N+1);
    visited.resize(N+1, false);
    dist.resize(N+1, 0);
    for (int i = 0; i < N; i++){
        int id;
        cin >> id;
        int edge , weight;
        while (1){
            cin >> edge;
            if (edge == -1)
                break;
            cin >> weight;
            nodes[id].push_back(make_pair(edge, weight));
        }
    }
    bfs(1, nodes);
    int index = findMaxDistanceIndex();
    fill(dist.begin(), dist.end(), 0);
    fill(visited.begin(), visited.end(), false);
    bfs(index, nodes);
    cout << dist[findMaxDistanceIndex()];

    return 0;
}