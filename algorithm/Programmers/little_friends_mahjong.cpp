#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

struct PointDir{
    Point p;
    int indexDir;
    int breakCnt;
};

bool boundary(int m, int n, Point p){
    if (p.x >= 0 && p.x < n && p.y >= 0 && p.y < m)
        return true;
    return false;
}

bool canMove(char c){
    if (c == '.')
        return true;
    return false;
}

bool checkSameLine(int indexDir1, int indexDir2){
    if (indexDir1 == -1 || indexDir1 % 2 == indexDir2 % 2)
        return true;
    return false;
}

bool findConnection(vector<string> &board, Point sp)
{
    char c = board[sp.y][sp.x];
    int dx[4] = {0,1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    queue<PointDir> q;

    q.push({sp, -1, 0});
    while (!q.empty()){
        PointDir pDir = q.front();
        q.pop();

        for (int i = 0; i < 4; i++){
            if (pDir.indexDir == (i + 2) % 4 || !checkSameLine(pDir.indexDir, i) && pDir.breakCnt == 1) continue;

            Point p = {pDir.p.x + dx[i], pDir.p.y + dy[i] };
            if (boundary(board.size(), board.front().size(), p)){
                if (board[p.y][p.x] == c) return true;
                if (!canMove(board[p.y][p.x])) continue;

                PointDir newPDir = {p, i, pDir.breakCnt};
                newPDir.breakCnt += checkSameLine(pDir.indexDir, newPDir.indexDir) ? 0 : 1;
                q.push(newPDir);
            }
        }
    }

    return false;
}

string solution(int m, int n, vector<string> board) {
    map<char, vector<Point>> alphabetInfo;
    string answer = "";

    for(int y = 0; y < m; y++){
        for(int x = 0; x < n; x++){
            if ('A' <= board[y][x] && board[y][x] <= 'Z'){
                alphabetInfo[board[y][x]].push_back({x, y});
            }
        }
    }

    int cnt = alphabetInfo.size();
    while (!alphabetInfo.empty()){
        char key = 0;
        for (auto info : alphabetInfo){
            if (findConnection(board, info.second[0])){
                key = info.first;
                answer += key;
                board[info.second[0].y][info.second[0].x] = '.';
                board[info.second[1].y][info.second[1].x] = '.';
                break;
            }
        }
        if (key == 0)
            break;
        alphabetInfo.erase(key);
    }

    return answer.size() != cnt ? "IMPOSSIBLE" : answer;
}

int main()
{
    int m = 3, n = 3;
    vector<string> board = {"DBA", "C*A", "CDB"};

    string answer = solution(m, n, board);
    cout << "\nanswer: " << answer << endl;

    return 0;
}