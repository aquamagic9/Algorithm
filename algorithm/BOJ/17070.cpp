#include <iostream>
using namespace std;

int moveHorizon[2][2] = {{1, 0}, {1, 1}};
int moveVertical[2][2] = {{0, 1}, {1, 1}};
int moveDiagonal[3][2] = {{1, 0}, {0, 1}, {1, 1}};
int map[16][16] = {0,};
int N, cnt = 0;
class Pos{
public:
    int x;
    int y;
    Pos(int x, int y){
        this->x = x;
        this->y = y;
    }
};

inline bool isHorizontal(const Pos &a, const Pos &b){
    return (b.x - a.x == 1) && (a.y == b.y);
}
inline bool isVertical(const Pos &a, const Pos &b){
    return (b.y - a.y == 1) && (a.x == b.x);
}
inline bool isDiagonal(const Pos &a, const Pos &b){
    return (b.x - a.x == 1) && (b.y - a.y == 1);
}
bool IsInMap(Pos end, bool isDiagonal){
    if (end.x >= 0 && end.x < N && end.y >= 0 && end.y < N && map[end.y][end.x] != 1){
        if (isDiagonal){
            if (map[end.y - 1][end.x] != 1 && map[end.y][end.x - 1] != 1){
                return true;
            }
        }
        else
            return true;
    }
    return false;
}

void dfs(Pos start, Pos end){
    if (end.x == N - 1 && end.y == N - 1){
        cnt++;
        return;
    }
    if (isHorizontal(start, end)){
        start = end;
        for (int i = 0; i < 2; i++){
            end = start;
            end.x += moveHorizon[i][0];
            end.y += moveHorizon[i][1];
            if (IsInMap(end, isDiagonal(start, end)))
                dfs(start, end);
        }
    }
    else if (isVertical(start, end)){
        start = end;
        for (int i = 0; i < 2; i++){
            end = start;
            end.x += moveVertical[i][0];
            end.y += moveVertical[i][1];
            if (IsInMap(end, isDiagonal(start, end)))
                dfs(start, end);
        }
    }
    else if (isDiagonal(start, end)){
        start = end;
        for (int i = 0; i < 3; i++){
            end = start;
            end.x += moveDiagonal[i][0];
            end.y += moveDiagonal[i][1];
            if (IsInMap(end, isDiagonal(start, end)))
                dfs(start, end);
        }
    }
    return ;
}

int main()
{

    cin >> N;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    Pos start(0,0), end(1,0);
    dfs(start, end);
    cout << cnt;

    return 0;
}
