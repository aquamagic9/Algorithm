#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int rowS = board.size(), colS = board[0].size();
    vector<int> row(colS + 1, 0);
    vector<vector<int>> imosBoard(rowS + 1, row);

    for (vector<int> v : skill){
        int r1 = v[1], c1 = v[2], r2 = v[3], c2 = v[4], degree = v[5];
        if (v[0] == 1)
            degree = -1 * degree;
        imosBoard[r1][c1] += degree;
        imosBoard[r1][c2 + 1] -= degree;
        imosBoard[r2 + 1][c1] -= degree;
        imosBoard[r2 + 1][c2 + 1] += degree;
    }

    for (int i = 0; i < rowS; i++){
        for (int j = 0; j < colS; j++){
            imosBoard[i][j + 1] += imosBoard[i][j];
        }
    }
    for (int i = 0; i < colS; i++){
        for (int j = 0; j < rowS; j++){
            imosBoard[j + 1][i] += imosBoard[j][i];
        }
    }
    for (int i = 0; i < rowS; i++){
        for (int j = 0; j < colS; j++){
            if (board[i][j] + imosBoard[i][j] > 0)
                answer++;
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>> board = {{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5},{5,5,5,5,5}};
    vector<vector<int>> skill = {{1,0,0,3,4,4},{1,2,0,2,3,2},{2,1,0,3,1,2},{1,0,1,3,3,1}};
    cout << solution(board, skill);

    return 0;
}