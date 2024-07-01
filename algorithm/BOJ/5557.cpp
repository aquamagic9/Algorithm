#include <iostream>
using namespace std;
typedef long long ll;

ll n, a[104], dp[104][21];

ll go(int idx, int sum){
    if(sum < 0 || sum >20)
        return 0;
    ll &ret = dp[idx][sum];
    if(ret)
        return ret;
    if(idx == n - 2){
        if(sum == a[n - 1])
            return 1;
        return 0;
    }
    ret += go(idx + 1, sum + a[idx + 1]);
    ret += go(idx + 1, sum - a[idx + 1]);
    return ret;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << go(0, a[0]) << "\n";

    return 0;
}