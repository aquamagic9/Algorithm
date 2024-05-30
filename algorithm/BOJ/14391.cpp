#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    int map[4][4];

    cin >> n >> m;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < m; j++){
            map[i][j] = s[j] - '0';
        }
    }

    int maxValue = 0;
    for (int b = 0; b < (1 << (n * m)); b++){
        int sum = 0;
        for (int y = 0; y < n; y++){
            int cur = 0;
            for (int x = 0; x < m; x++){
                int k = y * m + x;
                if ((b & (1 << k)) == 0){
                    cur = cur * 10 + map[y][x];
                }
                else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        for (int x = 0; x < m; x++){
            int cur = 0;
            for (int y = 0; y < n; y++){
                int k = y * m + x;
                if ((b & (1 << k)) != 0){
                    cur = cur * 10 + map[y][x];
                }
                else{
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }
        maxValue = max(maxValue, sum);
    }
    cout << maxValue;

    return 0;
}