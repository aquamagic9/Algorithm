#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

#define INF 2147483647

struct Point{
    int r;
    int c;
    int cnt;
};

struct Card{
    int num;
    int r;
    int c;
};

struct CardPair{
    Card c1;
    Card c2;
};

bool inBoard(int size, int r, int c){
    return r >= 0 && r < size && c >= 0 && c < size;
}

int bfs(int r1, int c1, int r2, int c2, vector<vector<int>> board){
    int minCnt = abs(r1 - r2) + abs(c1 - c2);
    if (minCnt == 0)
        return 0;
    int boardSize = 4;
    int dc[4] = {0, 1, 0, -1};
    int dr[4] = {1, 0, -1, 0};
    queue<Point> q;
    q.push({r1, c1, 0});

    while(!q.empty()){
        Point p = q.front(); q.pop();
        if (p.cnt >= minCnt){
            break;
        }
        if (p.r == r2 && p.c == c2){
            minCnt = p.cnt;
            return minCnt;
        }
        for (int i = 0; i < 8; i++){
            if (i >= 4){
                int dirInd = i % 4;
                Point np = p;
                while (inBoard(boardSize, np.r + dr[dirInd], np.c + dc[dirInd])){
                    np.r += dr[dirInd]; np.c += dc[dirInd];
                    if (board[np.r][np.c] != 0) {
                        break;
                    }
                }
                q.push({np.r, np.c, np.cnt + 1});
            }
            else{
                if (inBoard(boardSize, p.r + dr[i], p.c + dc[i])){
                    q.push({p.r + dr[i], p.c + dc[i], p.cnt + 1});
                }
            }
        }
    }

    return minCnt;
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = INF;

    vector<Card> cardVec;
    vector<CardPair> cardPairVec;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board[i].size(); j++){
            if (board[i][j]){
                cardVec.push_back({board[i][j], i, j});
            }
        }
    }
    for (int i = 0; i < cardVec.size(); i++){
        for (int j = i + 1; j < cardVec.size(); j++){
            if (cardVec[i].num == cardVec[j].num){
                CardPair tmp;
                tmp.c1 = cardVec[i];
                tmp.c2 = cardVec[j];
                cardPairVec.push_back(tmp);
            }
        }
    }

    int n = cardPairVec.size();
    vector<int> index(n);
    for (int i = 0; i < n; i++)
        index[i] = i;

    do{
        for (int i = 0; i < pow(2, n); i++){
            vector<vector<int>> newBoard = board;
            vector<Card> cards(n * 2);
            for (int j = n - 1; j >= 0; j--){
                cards[j * 2] = i & (1 << j) ? cardPairVec[index[j]].c1 : cardPairVec[index[j]].c2;
                cards[j * 2 + 1] = i & (1 << j) ? cardPairVec[index[j]].c2 : cardPairVec[index[j]].c1;
            }
            int cnt = 0;
            cnt += bfs (r, c, cards[0].r, cards[0].c, newBoard);
            for (int j = 0; j < n * 2 - 1; j++) {
                cnt += bfs(cards[j].r, cards[j].c, cards[j + 1].r, cards[j + 1].c, newBoard);
                newBoard[cards[j].r][cards[j].c] = 0;
                newBoard[cards[j + 1].r][cards[j + 1].c] = 0;
            }
            answer = min(cnt + n * 2, answer);
        }
    }while(next_permutation(index.begin(), index.end()));

    return answer;
}

int main()
{
    vector<vector<int>> board = {{1,0,0,3},{2,0,0,0},{0,0,0,2},{3,0,1,0}};
    int r = 1, c = 0;
//    vector<vector<int>> board = {{3,0,0,2},{0,0,1,0},{0,1,0,0},{2,0,0,3}};
//    int r = 0, c = 1;

    cout << solution(board, r, c);

    return 0;
}