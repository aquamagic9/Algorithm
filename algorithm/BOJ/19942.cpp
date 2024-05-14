#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N, mp, mf, ms, mv, minCost = 10000;
vector<int> v[15];
vector<int> result, minimumConditions(4);

string vectorToString(const vector<int> &vec){
    string s = "";
    for (int i = 0; i < vec.size(); i++){
        s += to_string(vec[i]);
    }
    return s;
}

bool checkCondition(const vector<int> &vec)
{
    vector<int> sum(5,0);
    for (const auto &index : vec){
        for (int i = 0; i < 5; i++){
            sum[i] += v[index][i];
        }
    }
    for (int i = 0; i < 4; i++){
        if (sum[i] < minimumConditions[i]){
            return false;
        }
    }
    if (minCost >= sum[4]){
        if (minCost == sum[4] && !result.empty() && vectorToString(result) < vectorToString(vec)){
            return true;
        }
        minCost = sum[4];
        result.clear();
        result.assign(vec.begin(), vec.end());
    }
    return true;
}

void combi(int start, int k, vector<int> vec)
{
    if (vec.size() == k){
        checkCondition(vec);
        return;
    }
    for (int i = start + 1; i < N; i++){
        vec.push_back(i);
        combi(i, k, vec);
        vec.pop_back();
    }
}

int main()
{
    cin >> N;
    cin >> minimumConditions[0] >> minimumConditions[1] >> minimumConditions[2] >> minimumConditions[3];

    for (int i = 0; i < N; i++){
        for (int j = 0; j < 5; j++){
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }

    for (int i = 1; i <= N; i++){
        vector<int> vec;
        combi(-1, i, vec);
    }
    if (result.empty()){
        cout << "-1";
    }
    else{
        cout << minCost << "\n";
        for (int i = 0; i < result.size(); i++){
            cout << result[i] + 1 << " ";
        }
    }

    return 0;
}