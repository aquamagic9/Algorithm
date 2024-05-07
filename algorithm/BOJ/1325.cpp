#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int maxCnt = 0;
vector<int> result;
int N, M;
vector<int> arr[10001];

int dfs(int num){
    if(arr[num].empty()){
        return 1;
    }
    int cnt = 0;
    for (int i = 0; i < arr[num].size(); i++){
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
        int cnt = dfs(i);
        cout << i << " " << cnt << "\n";
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