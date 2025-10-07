#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> splitByChar(string s, char c){
    vector<string> splittedStr;

    while (!s.empty()){
        splittedStr.push_back(s.substr(0, s.find(c)));
        s.erase(0, s.find(c) + 1);
    }

    return splittedStr;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, int> strToIndex;

    for (int i = 0; i < id_list.size(); i++)
        strToIndex[id_list[i]] = i;

    vector<int> row(id_list.size() + 1, 0);
    vector<vector<int>> table(id_list.size(), row);

    for (string s : report){
        s += ' ';
        vector<string> strs = splitByChar(s, ' ');
        int to = strToIndex[strs[1]];
        int from = strToIndex[strs[0]];
        if (table[to][from] == 0)
            table[to][table[to].size() - 1]++;
        table[to][from]++;
    }

    vector<int> froms(id_list.size(), 0);
    for (int i = 0; i < table.size(); i++){
        if (!(table[i][table[i].size() - 1] >= k))
            continue;
        int cnt = 0;
        for (int j = 0; j < table[i].size() - 1; j++){
            if (table[i][j])
                froms[j]++;
        }
    }
    answer = froms;

    return answer;
}

int main()
{
//    vector<string> id_list = {"muzi", "frodo", "apeach", "neo"};
//    vector<string> report = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    vector<string> id_list = {"con", "ryan"};
    vector<string> report = {"ryan con", "ryan con", "ryan con", "ryan con"};
    int k = 3;

    vector<int> result = solution(id_list, report, k);
    for (int n : result){
        cout << n << " ";
    }

    return 0;
}