#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int dwarfCnt = 9, originDwarfCnt = 7, sumOfHeightsOfDwarves = 100;
vector<int> dwarves(dwarfCnt);
bool printOnce = false;
void FindOriginDwarf(vector<int> &v)
{
    if (printOnce)
        return;
    int sum = 0;
    vector<int> foundDwarves(originDwarfCnt);
    for (int i = 0; i < v.size(); i++){
        sum += dwarves[v[i]];
        foundDwarves[i] = dwarves[v[i]];
    }
    if (sum == sumOfHeightsOfDwarves){
        printOnce = true;
        sort(foundDwarves.begin(), foundDwarves.end());
        for (int value : foundDwarves)
            cout << value << "\n";
    }
}
void combi(int start, vector<int> &v)
{
    if (v.size() == originDwarfCnt){
        FindOriginDwarf(v);
        return;
    }
    for (int i = start + 1; i < dwarfCnt; i++){
        v.push_back(i);
        combi(i, v);
        v.pop_back();
    }
    return;
}

int main()
{
    for (int i = 0; i < dwarfCnt; i++)
    {
        cin >> dwarves[i];
    }
    vector<int> v;
    combi(-1, v);

    return 0;
}

