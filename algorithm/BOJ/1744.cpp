#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> m_pq;
    int zero_cnt = 0;
    int one_cnt = 0;
    int N;

    cin >> N;
    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        if (tmp < 0){
            m_pq.push(tmp);
        }
        else if (tmp == 0){
            zero_cnt++;
        }
        else if (tmp == 1){
            one_cnt++;
        }
        else{
            pq.push(tmp);
        }
    }
    int max = one_cnt;
    while (pq.size() > 1){
        int tmp1 = pq.top();
        pq.pop();
        int tmp2 = pq.top();
        pq.pop();
        max += tmp1 * tmp2;
    }
    if (pq.size() == 1)
        max += pq.top();
    while (m_pq.size() > 1){
        int tmp1 = pq.top();
        pq.pop();
        int tmp2 = pq.top();
        pq.pop();
        max += tmp1 * tmp2;
    }
    if (m_pq.size() == 1 && zero_cnt == 0)
        max += m_pq.top();
    cout << max;

    return 0;
}