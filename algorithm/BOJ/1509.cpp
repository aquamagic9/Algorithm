#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> v[2501];
int strSize, minValue = 2500;
bool hasValue(const vector<int> a, int k){
    for (int i = 0; i < a.size(); i++){
        if (a[i] == k){
            return true;
        }
    }
    return false;
}

void dfs(int index, int cnt)
{
    if (minValue < cnt){
        return;
    }
    if (index == strSize){
        minValue = min(minValue, cnt);
        return;
    }
    for (int i = 0; i < v[index].size(); i++){
        dfs(index + v[index][i] + 1, cnt + 1);
    }
}

int main()
{
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    strSize = s.size();
    for (int i = 0; i < strSize; i++) {
        for (int j = 0; j < strSize - i; j++) {
            if (s[j] == s[j + i]) {
                if ((i == 0 || i == 1) || (j + 1 < strSize && hasValue(v[j + 1], i - 2))) {
                    v[j].push_back(i);
                }
            }
        }
    }
    dfs(0, 0);
    cout << minValue;

    return 0;
}