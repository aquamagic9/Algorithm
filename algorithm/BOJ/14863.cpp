#include <iostream>
using namespace std;
typedef long long ll;
int n, k, dp[101][100001];
struct B{
    int _time, pay;
};
B a[101], b[101];

int go(int here, int _time){
    if(here == n)
        return 0;

    int &ret = dp[here][_time];

    if(ret)
        return ret;
    ret = -1e6;
    if(_time - a[here]._time >= 0)
        ret = max(ret, go(here + 1, _time - a[here]._time) + a[here].pay);
    if(_time - b[here]._time >= 0)
        ret = max(ret, go(here + 1, _time - b[here]._time) + b[here].pay);

    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i]._time >> a[i].pay >> b[i]._time >> b[i].pay;
    }

    cout << go(0, k) << "\n";

    return 0;
}
