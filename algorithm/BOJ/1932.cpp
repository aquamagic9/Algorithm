#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v[n + 1];
    int col = 1, num;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < col; j++){
            cin >> num;
            v[i].push_back(num);
        }
        col++;
    }
    v[n].assign(n + 1, 0);
    for (int i = 1; i <= n; i++){
        for (int j = 0; j < v[i].size(); j++){
           int cost = 0;
           if (j - 1 >= 0){
               cost = max(cost, v[i - 1][j - 1]);
           }
           if (j < i){
               cost = max(cost, v[i - 1][j]);
           }
           v[i][j] += cost;
        }
    }
    int maxValue = 0;
    for (int i = 0; i <= n; i++){
        maxValue = max(maxValue, v[n][i]);
    }
    cout << maxValue;

    return 0;
}