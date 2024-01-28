#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void FindMinStep(vector<int> v);
int main() {
    int N, M;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> M;
        vector<int> v(M);
        for (int j = 0; j < M; j++)
        {
            cin >> v[j];
        }
        FindMinStep(v);
    }


    return 0;
}

void FindMinStep(vector<int> v)
{
    sort(v.begin(), v.end());
    vector<int> newV(v.size());
    int index = 0;
    for (int i = 0; i < newV.size(); i++)
    {
        if (i % 2 == 0)
        {
            newV[index] = v[i];
        }
        else
        {
            newV[newV.size() - 1 - index] = v[i];
            index++;
        }
    }

    int min = v.back() - v.front();
    for (int i = 0; i < newV.size() - 1; i++) {
        if (min > abs(newV[i + 1] - newV[i]))
        {
            min = abs(newV[i + 1] - newV[i]);
        }
    }
    if (min > abs(newV.front() - newV.back()))
    {
        min = abs(newV.front() - newV.back());
    }

    cout << min << "\n";
}