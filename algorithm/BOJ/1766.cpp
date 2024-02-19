#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;

    cin >> N >> M;
    vector<vector<int>> solvingOrderRules(N + 1);
    vector<int> inDegree(N + 1, 0);
    for (int i = 0; i < M; i++){
        int senior, subordinated;
        cin >> senior >> subordinated;
        solvingOrderRules[senior].push_back(subordinated);
        inDegree[subordinated]++;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++){
        if (inDegree[i] == 0){
            pq.push(i);
        }
    }
    for (int i = 1; i <= N; i++){
        if (pq.empty()){
            cout << "It has cycle" << '\n';
        }
        int node = pq.top();
        cout << node << " ";
        pq.pop();
        for (int j = 0; j < solvingOrderRules[node].size(); j++){
            if (--inDegree[solvingOrderRules[node][j]] == 0){
                pq.push(solvingOrderRules[node][j]);
            }
        }
    }

    return 0;
}