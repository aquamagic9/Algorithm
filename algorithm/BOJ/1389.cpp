#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> user[101];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < M; i++){
        int friend1, friend2;
        cin >> friend1 >> friend2;
        user[friend1].push_back(friend2);
        user[friend2].push_back(friend1);
    }

    int result, minValue;
    for (int i = 1; i <= N; i++){
        int sum = 0;
        vector<int> visit(N + 1, 0);
        queue<int> q;
        q.push(i);
        visit[i] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            sum += visit[node];
            for (int j = 0; j < user[node].size(); j++){
                if (visit[user[node][j]] == 0){
                    visit[user[node][j]] = visit[node] + 1;
                    q.push(user[node][j]);
                }
            }
        }
        if (i == 1){
            minValue = sum;
            result = i;
        }
        else if (minValue > sum) {
            minValue = sum;
            result = i;
        }
    }
    cout << result;

    return 0;
}