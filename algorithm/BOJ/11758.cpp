#include <iostream>
using namespace std;

typedef pair<int, int> Vec;
int CounterClockWise(Vec A, Vec B);
int main()
{
    int pos[3][2];

    for (int i = 0; i < 3; i++)
        cin >> pos[i][0] >> pos[i][1];

    Vec vec1(pos[1][0] - pos[0][0], pos[1][1] - pos[0][1]);
    Vec vec2(pos[2][0] - pos[0][0], pos[2][1] - pos[0][1]);
    int result = CounterClockWise(vec1, vec2);
    if (result == 0)
        cout << 0;
    else if (result > 0)
        cout << 1;
    else
        cout << -1;

    return 0;
}

int CounterClockWise(Vec A, Vec B) {
    return A.first * B.second - A.second * B.first ;
}