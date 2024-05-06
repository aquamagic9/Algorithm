#include <iostream>
#include <vector>
using namespace std;

vector<int> v[50];

int dfs(int node)
{
    int cnt = 0;
    if (v[node].size() == 0){
        return 1;
    }
    for(int i = 0; i < v[node].size(); i++){
        cnt += dfs(v[node][i]);
    }
    return cnt;
}

int main()
{

    int N, removeNode, rootNode;

    cin >> N;
    for (int i = 0; i < N; i++){
        int parent;
        cin >> parent;
        if (parent == -1){
            rootNode = i;
            continue;
        }
        v[parent].push_back(i);
    }
    cin >> removeNode;
    if (removeNode == rootNode){
        cout << 0;
        return 0;
    }

    v[removeNode].clear();
    bool check = false;
    for(int i = 0; i < N; i++){
        if (check)
            break;
        for(int j = 0; j < v[i].size(); j++){
            if (v[i][j] == removeNode){
                v[i].erase(v[i].begin() + j);
                check = true;
                break;
            }
        }
    }
    int totalLeafCnt = dfs(rootNode);

    cout << totalLeafCnt;

    return 0;
}