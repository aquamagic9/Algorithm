#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (vector<int> command : commands)
    {
        int first_index = command[0] - 1;
        int second_index = command[1] - 1;
        vector<int> result;
        for(int i = first_index; i <= second_index; i++)
        {
            result.push_back(array[i]);
        }
        sort(result.begin(), result.end());
        answer.push_back(result[command[2] - 1]);
    }

    return answer;
}