#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int testCase, n;

    cin >> testCase;

    for (int i = 1; i <= testCase; i++)
    {
        int result = 1;
        map<string, int> fashionMap;

        cin >> n;
        for (int j = 0; j < n; j++)
        {
            string item, type;
            cin >> item >> type;
            fashionMap[type]++;
        }
        for(auto p: fashionMap)
        {
            result *= p.second + 1;
        }
        result--;
        cout << result << "\n";
    }

    return 0;
}