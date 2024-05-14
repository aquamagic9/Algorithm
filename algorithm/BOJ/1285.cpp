#include <iostream>
#include <string>
using namespace std;

int N, result = 2147483647;
int a[20];
void go (int row)
{
    if (row == N){
        int sum = 0;
        for (int i = 1; i < (1 << N); i = i << 1){
            int cnt = 0;
            for (int j = 0; j < N; j++) {
                if (a[j] & i) {
                    cnt++;
                }
            }
            sum += min(cnt, N - cnt);
        }
        result = min(result, sum);
        return;
    }
    go(row + 1);
    a[row] = ~a[row];
    go(row + 1);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            if (row[j] == 'T')
                a[i] |= (1 << j);
        }
    }
    go(0);
    cout << result;

    return 0;
}