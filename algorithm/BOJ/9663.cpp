#include <iostream>
#include <vector>
using namespace std;

class Pos
{
public:
    int _x;
    int _y;
    Pos(int x, int y)
    {
        _x = x;
        _y = y;
    }
};
int cnt = 0;
void NQueen(vector<bool> &visit, int N, int index);
bool CheckCross(Pos newPos);
vector<Pos> posVec;

int main()
{
    int N;

    cin >> N;
    vector<bool> visit(N, false);
    NQueen(visit, N, 0);
    cout << cnt;

    return 0;
}

void NQueen(vector<bool> &visit, int N, int index)
{
    for (int i = 0; i < N; i++)
    {
        if (visit[i] == false && !CheckCross(Pos(index, i)))
        {
            visit[i] = true;
            posVec.push_back(Pos(index, i));
            if (index != N - 1)
            {
                NQueen(visit, N, index + 1);
            }
            else
            {
                cnt++;
            }
            posVec.pop_back();
            visit[i] = false;
        }
    }
}

bool CheckCross(Pos newPos)
{
    for (int i = 0; i < posVec.size(); i++)
    {
        if (abs(posVec[i]._x - newPos._x) == abs(posVec[i]._y - newPos._y))
        {
            return true;
        }
    }
    return false;
}
