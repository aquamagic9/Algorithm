#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> infos, vector<string> query) {
    vector<int> answer;
    unordered_map<string, vector<int>> Data;

    for (string info : infos){
        stringstream ss(info);
        vector<string> input(5);
        ss >> input[0] >> input[1] >> input[2] >> input[3] >> input[4];
        for (int mask = 0; mask < 16; mask++){
            string key = "";
            for (int k = 0; k < 4; k++){
                if ((mask >> k) % 2){
                    key += input[k];
                }
                else{
                    key += "-";
                }
            }
            Data[key].push_back(stoi(input[4]));
        }
    }

    for (auto &d : Data){
        sort(d.second.begin(), d.second.end());
    }

    for (string q : query){
        stringstream ss(q);
        vector<string> input(5);
        string tmp;
        ss >> input[0] >> tmp >> input[1] >> tmp >> input[2] >> tmp >> input[3] >> input[4];
        string key = input[0] + input[1] + input[2] + input[3];
        answer.push_back(Data[key].size() - (lower_bound(Data[key].begin(), Data[key].end(), stoi(input[4])) - Data[key].begin()));
    }

    return answer;
}

int main()
{
    vector<string> info = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> query = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};

    vector<int> results = solution(info, query);
    for(int k : results){
        cout << k << " ";
    }

    return 0;
}