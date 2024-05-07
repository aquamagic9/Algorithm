#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int maxCnt = 0;
int N, M;
vector<int> result;
vector<int> arr[10001];
int visited[10001];

int dfs(int num){
    visited[num] = 1;
    int cnt = 1;
    for (int i = 0; i < arr[num].size(); i++){
        if (visited[arr[num][i]])
            continue;
        cnt += dfs(arr[num][i]);
    }
    return cnt;
}

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        arr[b].push_back(a);
    }

    for (int i = 1; i <= N; i++){
        if (arr[i].empty()){
            continue;
        }
        memset(visited, 0, sizeof(visited));
        int cnt = dfs(i);
        if (maxCnt < cnt){
            result.clear();
            result.push_back(i);
            maxCnt = cnt;
        }
        else if (maxCnt == cnt){
            result.push_back(i);
        }
    }

    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

    return 0;
}