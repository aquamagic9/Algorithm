#include <iostream>
#include <vector>
int map[10][10];
int N, minGold = 2147483647;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,-1,0,1};
using namespace std;

bool checkCondition(const vector<int> &v){
    int size = N - 2;
    for (int i = 0; i < v.size(); i++){
        int x = v[i] % size;
        int y = v[i] / size;
        int nx = v[(i + 1) % v.size()] % size;
        int ny = v[(i + 1) % v.size()] / size;
        if (abs(x - nx) + abs(y - ny) <= 2){
            return false;
        }
    }
    return true;
}

int sumGold(const vector<int> &v)
{
    int size = N - 2, sum = 0, offset = 1;
    for (int i = 0; i < v.size(); i++){
        int x = v[i] % size + offset;
        int y = v[i] / size + offset;
        sum += map[y][x];
        for (int j = 0; j < 4; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx >= 0 && nx < N && ny >= 0 && ny < N){
                sum += map[ny][nx];
            }
        }
    }
    return sum;
}

void combi(int start, vector<int> v)
{
    if (v.size() == 3){
        if (checkCondition(v))
        {
            int gold = sumGold(v);
            if (gold < minGold){
                minGold = gold;
            }
        }
        return;
    }
    for (int i = start + 1; i < (N - 2) * (N - 2); i++)
    {
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }
    vector<int> v;
    combi(-1, v);
    cout << minGold;

    return 0;
}