#include <string>
#include <vector>

using namespace std;

void dfs(int j, int n, vector<vector<int>> &computers){
    if (computers[j][j] == 0)
        return ;
    computers[j][j] = 0;
    for(int i = 0 ; i < n; i++){
        if (computers[j][i] == 1)
            dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++){
        if (computers[i][i] != 0)
        {
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}