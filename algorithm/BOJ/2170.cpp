#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    int N;

    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<pair<int, int>> lines(N);
    for (int i = 0; i < N; i++){
        cin >> lines[i].first >> lines[i].second;
    }
    sort(lines.begin(), lines.end(), cmp);
    int lastPos = lines[0].second;
    int lineLength = lines[0].second - lines[0].first;
    for (int i = 1; i < N; i++)
    {
        if (lastPos > lines[i].first){
            if (lastPos < lines[i].second){
                lineLength += lines[i].second - lastPos;
                lastPos = lines[i].second;
            }
        }
        else{
            lineLength += lines[i].second - lines[i].first;
            lastPos = lines[i].second;
        }
    }
    cout << lineLength;

    return 0;
}