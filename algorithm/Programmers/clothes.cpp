#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector <pair<string, int>> category;

    for (vector <string> cloth : clothes) {
        int flag = 0;
        for (int i = 0; i < category.size(); i++) {
            if (cloth[1] == category[i].first){
                category[i].second++;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            category.push_back(pair<string, int> (cloth[1], 1));
        }
    }
    for (int i = 0; i < category.size(); i++) {
        answer = answer * (category[i].second + 1);
        //cout << category[i].first << " " << category[i].second << endl;
    }
    answer = answer - 1;

    return answer;
}