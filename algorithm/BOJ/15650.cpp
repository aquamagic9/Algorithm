#include <iostream>
using namespace std;

#define MAX 9
int N, M;
int arr[MAX], visit[MAX];

void SelectNum(int index);

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL);

    cin >> N >> M;
    for (int i = 1; i < MAX; i++)
        visit[i] = 0;
    SelectNum(1);
    return 0;
}

void SelectNum(int index)
{
    if (index > M)
    {
        for (int i = 1; i <= M; i++)
        {
            cout << to_string(arr[i]) + " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!visit[i])
        {
            if (index != 1 && arr[index - 1] > i)
            {
                continue;
            }
            arr[index] = i;
            visit[i] = 1;
            SelectNum(index + 1);
            visit[i] = 0;
        }
    }
}
