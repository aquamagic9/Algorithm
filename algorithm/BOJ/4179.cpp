#include <iostream>
#include <vector>
using namespace std;

const int maxInt = 2147483647;
const int fireAndWall = 0;
const int playerVisited = 0;
const int canMove = 1;

int R, C, minValue;
vector<vector<char>> map;
vector<vector<int>> visited;
vector<vector<int>> pVisited;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(const pair<int, int> &pos, const vector<pair<int, int>> &fireZone, int distance)
{
    int x = pos.first;
    int y = pos.second;

    pVisited[y][x] = playerVisited;
    if (x == 0 || x == C - 1 || y == 0 || y == R - 1){
        minValue = min(minValue, distance);
        pVisited[y][x] = canMove;
        return;
    }

    vector<pair<int,int>> newFireZone;
    for (const auto &fire : fireZone){
        for (int i = 0; i < 4; i++){
            int fx = fire.first + dx[i];
            int fy = fire.second + dy[i];
            if (fx >= 0 && fx < C && fy >= 0 && fy < R && visited[fy][fx] == canMove){
                newFireZone.push_back(make_pair(fx, fy));
                visited[fy][fx] = fireAndWall;
            }
        }
    }

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < C && ny >= 0 && ny < R && pVisited[ny][nx] == canMove && visited[ny][nx] == canMove){
            dfs(make_pair(nx, ny), newFireZone, distance + 1);
        }
    }
    for (const auto &fire : newFireZone){
        visited[fire.second][fire.first] = canMove;
    }
    pVisited[y][x] = canMove;
}

int main()
{
    cin >> R >> C;

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<pair<int, int>> fireZone;
    pair<int, int> jPos;
    minValue = maxInt;

    for (int i = 0; i < R; i++){
        vector<char> row(C);
        vector<int> vRow(C, canMove);
        vector<int> pRow(C, canMove);
        for (int j = 0; j < C; j++){
            cin >> row[j];
            if (row[j] == '#' || row[j] == 'F'){
                vRow[j] = fireAndWall;
                pRow[j] = fireAndWall;
            }
            if (row[j] == 'F'){
                fireZone.push_back(make_pair(j, i));
            }
            if (row[j] == 'J'){
                jPos = {j, i};;
                pRow[j] = playerVisited;
            }
        }
        map.push_back(row);
        visited.push_back(vRow);
        pVisited.push_back(pRow);
    }

    dfs(jPos, fireZone, 0);

    if (minValue != maxInt){
        cout << minValue + 1;
    }
    else {
        cout << "IMPOSIBLE";
    }

    return 0;
}