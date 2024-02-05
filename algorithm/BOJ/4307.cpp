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
        vector<int> posVec;
        int minDiff = l / 2;
        int tmp;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            if (tmp == 0 || tmp == l)
                continue;
            posVec.push_back(tmp);
            if (minDiff > abs(tmp - l / 2))
                minDiff = abs(tmp - l / 2);
        }
        int max;
        if (!posVec.empty())
        {
            sort(posVec.begin(), posVec.end());
            max = posVec.front() < l - posVec.back() ? l - posVec.front() : posVec.back();
        }
        else
        {
            max = 0;
        }
        cout << l / 2 - minDiff << " " << max << '\n';
    }

    return 0;
}