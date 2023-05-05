#include <iostream>
#include <vector>
#include <queue>
using namespace std;
static int map[101][101];
int main()
{
    int N, M;

    cin >> N >> M;
    for (int i = 0; i < N; i++){
        string input;
        cin >> input;
        for (int j = 0; j < input.size(); j++)
            map[i][j]= input[j] - '0';
    }

    queue<pair<int,int>> my_queue;
    my_queue.push(make_pair(0,0));
    pair<int, int> now;
    while(!my_queue.empty() || my_queue.front().first == N - 1 && my_queue.front().second == M - 1){
        now = my_queue.front();
        my_queue.pop();
        //right
        if(now.second + 1 < M && map[now.first][now.second + 1])
        {
            if (map[now.first][now.second + 1] == 1 || map[now.first][now.second] + 1 < map[now.first][now.second + 1])
            {
                map[now.first][now.second + 1] = map[now.first][now.second] + 1;
                my_queue.push(make_pair(now.first, now.second + 1));
            }

        }
        //left
        if(now.second - 1 >= 0 && map[now.first][now.second - 1]){
            if (map[now.first][now.second - 1] == 1 || map[now.first][now.second] + 1 < map[now.first][now.second - 1])
            {
                map[now.first][now.second - 1] = map[now.first][now.second] + 1;
                my_queue.push(make_pair(now.first, now.second - 1));
            }
        }
        //up
        if(now.first - 1 >= 0 && map[now.first - 1][now.second]){
            if (map[now.first - 1][now.second] == 1 || map[now.first][now.second] + 1 < map[now.first - 1][now.second]){
                map[now.first - 1][now.second] = map[now.first][now.second] + 1;
                my_queue.push(make_pair(now.first - 1, now.second));
            }
        }
        //down
        if(now.first + 1 < N && map[now.first + 1][now.second]){
            if (map[now.first + 1][now.second] == 1 || map[now.first][now.second] + 1 < map[now.first + 1][now.second])
            {
                map[now.first + 1][now.second] = map[now.first][now.second] + 1;
                my_queue.push(make_pair(now.first + 1, now.second));
            }
        }
    }

    cout << map[N - 1][M - 1];
    return 0;
}