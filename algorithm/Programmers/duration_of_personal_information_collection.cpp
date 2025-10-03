#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int stringToDays(string s){
    int year = stoi(s.substr(0, 4));
    int month = stoi(s.substr(5, 2));
    int day = stoi(s.substr(8, 2));
    return (year * 12 + month) * 28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> termInfo;
    int todayByDays = stoi(today.substr());

    for (string s : terms){
        termInfo[s[0]] = stoi(s.substr(2, s.size() - 2)) * 28;
    }

    for (int i = 0; i < privacies.size(); i++){
        char term = privacies[i][privacies[i].size() - 1];
        int num = stringToDays(privacies[i]);
        //cout << stringToDays(today) << " " << num << " " << termInfo[term] << endl;
        if (stringToDays(today) >= num + termInfo[term]){
            answer.push_back(i + 1);
        }
    }

    return answer;
}

int main()
{
    string today = "2020.01.01";
    vector<string> terms = {"Z 3", "D 5"};
    vector<string> privacies = {"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"};

    vector<int> answer = solution(today, terms, privacies);
    for (int n : answer){
        cout << n << " ";
    }

    return 0;
}