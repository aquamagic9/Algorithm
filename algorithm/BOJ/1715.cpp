#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int N;

    cin >> N;
    priority_queue<int, vector<int>, greater<int>> queue;
    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        queue.push(tmp);
    }
    int cnt = 0;
    while (queue.size() > 1){
        int first = queue.top();
        queue.pop();
        int second = queue.top();
        queue.pop();
        cnt += (first + second);
        queue.push(first+second);
    }
    cout << cnt;
    return 0;
}