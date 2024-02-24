#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int N, M;
    queue<pair<int, int>> q, newQ;
    int cnt = 0;

    cin >> M >> N;
    vector<vector<int>> arr(N);

    for (int i = 0; i < N; i++){
        vector<int> row(M);
        for (int j = 0; j < M; j++){
            cin >> row[j];
            if (row[j] == 1){
                q.push(make_pair(j, i));
            }
            else if (row[j] == -1){
                cnt++;
            }
        }
        arr[i] = row;
    }

    int dx[4] = {0, 0, 1,-1};
    int dy[4] = {1,-1, 0,0};
    int resultCnt = 0;
    while(true){
        if (q.empty()){
            if (newQ.empty()){
                break;
            }
            resultCnt++;
            q = newQ;
            queue<pair<int, int>> tmp;
            newQ = tmp;
        }
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && arr[ny][nx] == 0){
                newQ.push(make_pair(nx, ny));
                arr[ny][nx] = 1;
            }
        }
    }
    resultCnt = cnt == N * M ? resultCnt : -1;
    cout << resultCnt;

    return 0;
}