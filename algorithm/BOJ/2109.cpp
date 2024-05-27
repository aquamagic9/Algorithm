#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int dp[10001];
int main()
{
    int n;

    cin >> n;
    int day, pay;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++){
        cin >> pay >> day;
        v.push_back(make_pair(pay, day));
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < n; i++){
        pay = v[i].first;
        day = v[i].second;
        int saveIndex = 0, minIndex = 0, minValue = 10001;
        for (int j = 1; j <= day; j++){
            if (dp[j] == 0) {
                saveIndex = j;
                break;
            }
            else if (dp[j] < pay && dp[j] < minValue){
                minIndex = j;
                minValue = dp[j];
            }
        }
        if (saveIndex != 0){
            dp[saveIndex] = pay;
        }
        else if (minIndex != 0){
            dp[minIndex] = pay;
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++){
        sum += dp[i];
    }
    cout << sum;

    return 0;
}