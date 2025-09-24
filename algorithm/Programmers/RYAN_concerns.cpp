#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool cmp(vector<int> t1, vector<int> t2){
    return t1[0] == t2[0] ? t1[1] < t2[1] : t1[0] < t2[0];
}

bool boundary(int n, int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool check(const vector<vector<int>> &board, int dist, int px, int py){
    for (int y = py - dist + 1; y < py + dist; y++){
        for (int x = px - dist + 1; x < px + dist; x++){
            if (boundary(board.size(), x, y) && (abs(y - py) + abs(x - px)) < dist && board[y][x]){
                return false;
            }
        }
    }
    return true;
}

void clearVector(vector<vector<int>> &vec)
{
    for (vector<int> &r : vec)
        for (int &c : r)
            c = 0;
    return ;
}

int findMaxCountByDist(int n, int dist){
    vector<int> r(n, 0);
    vector<vector<int>> board(n, r);
    int count = 0, maxCnt = 0;

    for (int start = 0; start < n; start++){
        count = 0;
        clearVector(board);
        for(int y = 0; y < n; y++){
            for (int x = y == 0 ? start : 0; x < n; x++){
                if (check(board, dist, x, y)){
                    board[y][x] = 1;
                    count++;
                }
            }
        }
        maxCnt = max(count, maxCnt);
    }

    return maxCnt;
}

int solution(int n, int m, vector<vector<int>> timetable) {
    int maxCount = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    sort(timetable.begin(), timetable.end(), cmp);
    for (auto t : timetable){
        while (!pq.empty() && pq.top() < t[0]){
            pq.pop();
        }
        pq.push(t[1]);
        maxCount = max((int)pq.size(), maxCount);
    }

    if (maxCount == 0 || maxCount == 1 || n == 1)
        return 0;

    if (maxCount == 2) return (n - 1) * 2;
//    if (maxCount == 3) return 4 * (n - 1) / 3;
//    if (maxCount == 4) return n - 1;

    int maxDistByN = 2 * (n - 1);
    int answer = 1;
    vector<int> maxCountByDist(maxDistByN + 1, 0);
    maxCountByDist[1] = n * n;
    maxCountByDist[2] = (n * n + 1) / 2;

    for (int dist = 3; dist <= maxDistByN; dist++){
        maxCountByDist[dist] = findMaxCountByDist(n, dist);
    }

    for (int dist = 2; dist <= maxDistByN; dist++){
        if (maxCountByDist[dist] < maxCount){
            return dist - 1;
        }
    }

    return answer;
}

int main()
{
    int n = 3, m = 2;
    vector<vector<int>> timetable = {{1170,1210}, {1200,1260}};

    int n2 = 6, m2 = 18;
    vector<vector<int>> timetable2 = {{1,100},{1,2},{1,3},{1,4},{1,5},{1,6}};

    int answer = solution(n2,m2,timetable2);
    cout << answer ;

    return 0;
}