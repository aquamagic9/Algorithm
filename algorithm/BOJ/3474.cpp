#include <iostream>
using namespace std;

int main()
{
    int T;

    ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++){
        int num, cnt = 0;
        cin >> num;
        for (int j = 5; j <= num; j *= 5){
            cnt += num / j;
        }
        cout << cnt << "\n";
    }

    return 0;
}