#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M, T, num, one, in[1001];
vector<int> v[1001], result;
queue<int> q;

void topologySort() {
    for (int i = 1; i <= N; i++) {
        if (in[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        result.push_back(x);

        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i];
            in[nx]--;
            if (in[nx] == 0)
                q.push(nx);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> T;
        cin >> one;
        for (int j = 1; j < T; j++) {
            cin >> num;
            v[one].push_back(num);
            in[num]++;
            one = num;
        }
    }
    topologySort();

    if (result.size() == N) {
        for (auto c : result)
            cout << c << "\n";
    }
    else
        cout<<0;
}