#include <iostream>
#include <queue>
using namespace std;

struct P{
    int a;
    int b;
    int c;
};

P damages[6] = {
        {1, 3, 9},
        {1, 9, 3},
        {3, 1, 9},
        {3, 9, 1},
        {9, 3, 1},
        {9, 1, 3}
};

int visit[61][61][61];

void solve(P scv){
    queue<P> q;
    q.push(scv);
    visit[scv.a][scv.b][scv.c];
    while (!q.empty()){
        int a = q.front().a;
        int b = q.front().b;
        int c = q.front().c;
        q.pop();
        if (a == 0 && b == 0 && c == 0){
            cout << visit[0][0][0];
            break;
        }
        for (int i = 0; i < 6; i++){
            int na = max(0, a - damages[i].a);
            int nb = max(0, b - damages[i].b);
            int nc = max(0, c - damages[i].c);
            if (visit[na][nb][nc] == 0){
                q.push({na, nb, nc});
                visit[na][nb][nc] = visit[a][b][c] + 1;
            }
        }
    }
}
int main()
{
    int N;
    cin >> N;
    int scv[3] = {0,0,0};
    for (int i = 0; i < N; i++){
        cin >> scv[i];
    }
    solve({scv[0], scv[1], scv[2]});


    return 0;
}