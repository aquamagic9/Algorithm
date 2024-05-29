#include <iostream>
using namespace std;

int main()
{
    int l = 64, X, sum, cnt = 0;

    cin >> X;
    sum = X;
    while (sum != 0 && l != 0){
        if (sum >= l){
            sum -= l;
            cnt++;
        }
        l = l / 2;
    }
    cout << cnt;

    return 0;
}