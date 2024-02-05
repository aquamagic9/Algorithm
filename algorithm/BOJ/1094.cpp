#include<iostream>
using namespace std;

int main()
{
    int X;
    int barLength = 64, cnt = 1;

    cin >> X;

    while (barLength != X)
    {
        barLength = barLength / 2;
        if (barLength >= X) {
            continue;
        }
        else {
            X = X - barLength;
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}