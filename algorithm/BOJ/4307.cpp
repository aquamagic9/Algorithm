#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int test_case;

    cin >> test_case;
    for (int i = 0; i < test_case; i++)
    {
        int l, n;
        cin >> l >> n;

        int minTime = 0, maxTime = 0, pos;
        for (int i = 0; i < n; i++){
            cin >> pos;
            minTime = max(minTime, min(pos, l - pos));
            maxTime = max(maxTime, max(pos, l - pos));
        }
        cout << minTime << " " << maxTime << '\n';
    }

    return 0;
}