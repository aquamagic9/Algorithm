#include <iostream>
using namespace std;
int arr[1025][1025];
int D[1025][1025];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;

    cin >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            D[i][j] = D[i - 1][j] + D[i][j - 1] - D[i - 1][j - 1] + arr[i][j];
        }
    }
    int x1, y1, x2, y2;
    for (int i = 0; i < M; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        int result = D[x2][y2] + D[x1 - 1][y1 - 1] - D[x1 - 1][y2] - D[x2][y1 - 1];
        cout << result << endl;
    }

    return 0;
}
