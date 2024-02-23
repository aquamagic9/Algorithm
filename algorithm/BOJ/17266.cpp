#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;
    vector<int> lights(M);
    for (int i = 0; i < M; i++){
        cin >> lights[i];
    }
    int maxDistance = 0;
    maxDistance = max(lights[0], maxDistance);
    maxDistance = max(N - lights[M - 1], maxDistance);
    for (int i = 0; i < lights.size() - 1; i++){
        maxDistance = max((lights[i + 1] - lights[i] + 1) / 2, maxDistance);
    }
    cout << maxDistance;

    return 0;
}