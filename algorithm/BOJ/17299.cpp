#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000001;
int cnt[MAX] = {};
int main()
{
    int N;
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        cnt[arr[i]]++;
    }

    for (int i = 0; i < N; i++)
    {
        bool flag = false;
        for (int j = i + 1; j < N; j++)
        {
            if (cnt[arr[j]] > cnt[arr[i]])
            {
                flag = true;
                cout << arr[j] << " ";
                break;
            }
        }
        if (!flag) {
            cout << -1 << " ";
        }
    }

    return 0;
}