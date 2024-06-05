#include <iostream>
using namespace std;

int mapSize;
int map[10][10];
int lCross[18], rCross[18];
int answer[2];

void tracking(int row, int col, int count, int color)
{
    if (col >= mapSize){
        row++;
        if (col % 2 == 0)
            col = 1;
        else
            col = 0;
    }
    if (row >= mapSize){
        answer[color] = max(answer[color], count);
        return;
    }
    if (map[row][col] && !lCross[mapSize - 1 - row + col] && !rCross[row + col])
    {
        lCross[mapSize - 1 - row + col] = 1;
        rCross[row + col] = 1;
        tracking(row, col + 2, count + 1, color);
        lCross[mapSize - 1 - row + col] = 0;
        rCross[row + col] = 0;
    }
    tracking(row, col + 2, count, color);
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> mapSize;
    for (int i = 0; i < mapSize; i++){
        for (int j = 0; j < mapSize; j++){
            cin >> map[i][j];
        }
    }

    tracking(0,0,0,0);
    tracking(0,1,0,1);

    cout << answer[0] + answer[1];

    return 0;
}