#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> result;
int maxDiff;

void dfs(int arrowCnt, int index, vector<int> &apeach, vector<int> &ryan){
    if (index == 11 || arrowCnt == 0){
        ryan[ryan.size() - 1] += arrowCnt;
        int score = 0;
        for (int i = 0; i < ryan.size(); i++){
            if (apeach[i] < ryan[i])
                score += 10 - i;
            else if (apeach[i])
                score -= 10 - i;
        }
        if (maxDiff < score){
            maxDiff = score;
            result = ryan;
        }
        else if (maxDiff == score){
            for (int i = apeach.size() - 1; i >= 0; i--){
                if (result[i] > ryan[i]){
                    return;
                }
                if (result[i] < ryan[i]){
                    result = ryan;
                    break;
                }
            }
        }
        return;
    }

    for (int i = index; i < apeach.size(); i++){
        int num = apeach[i] + 1;
        if (arrowCnt < num){
            num = arrowCnt;
        }
        ryan[i] = num;
        dfs(arrowCnt - num, i + 1, apeach, ryan);
        ryan[i] = 0;
    }
}

vector<int> solution(int n, vector<int> info) {
    result.assign(info.size(), 0);
    maxDiff = 0;
    vector<int> ryan(info.size(), 0);

    dfs(n, 0, info, ryan);

    int sumA = 0, sumR = 0;
    for (int i = 0; i < info.size(); i++){
        if (info[i] < result[i])
            sumR += (result[i] != 0) * (10 - i);
        else
            sumA += (info[i] != 0) * (10 - i);
    }
    if (sumA >= sumR){
        result.clear();
        result.push_back(-1);
    }

    return result;
}

int main()
{
    int n = 10;
    //vector<int> info = {2,1,1,1,0,0,0,0,0,0,0};
    vector<int> info = {0,0,0,0,0,0,0,0,3,4,3};

    vector<int> results = solution(n, info);
    for (int n : results){
        cout << n << " ";
    }

    return 0;
}