#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int k;
vector<int> v[11];
int a[1024];

void solve(int depth, int index){
    v[depth].push_back(a[index]);
    if (depth == k){
        return;
    }
    solve(depth + 1, index - (pow(2, k - depth)) / 2);
    solve(depth + 1, index + (pow(2, k - depth)) / 2);
}
int main()
{
    cin >> k;
    for(int i = 0; i < pow(2, k) - 1; i++){
        cin >> a[i];
    }
    solve(1, (pow(2, k) - 1) / 2);
    for (int i = 1; i <= k; i++){
        for (int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}