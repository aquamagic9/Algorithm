#include <iostream>
using namespace std;

int getCount(int n) {
    int cnt = 0;
    while (n > 0) {
        if (n % 2 == 1) cnt++;
        n /= 2;
    }
    return cnt;
}

int main()
{
    int N, K, ans;

    cin >> N >> K;
    ans = N;
    while (1){
        if (getCount(ans) <= K)
            break;
        else
            ans++;
    }
    cout << ans - N;

    return 0;
}