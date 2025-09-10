#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmpPair(pair<int, int> &a, pair<int, int> &b){
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}

bool cmp(pair<string, vector<pair<int, int>>> &a,
         pair<string, vector<pair<int, int>>> &b){
    int sumA = 0, sumB = 0;

    for(auto pair : a.second){
        sumA += pair.first;
    }
    for(auto pair : b.second){
        sumB += pair.first;
    }
    return sumA > sumB;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> m;

    for(int i = 0; i < plays.size(); i++){
        m[genres[i]].push_back(make_pair(plays[i], i));
    }
    vector<pair<string, vector<pair<int, int>>>> vec(m.begin(), m.end());
    sort(vec.begin(), vec.end(), cmp);
    for(auto &genre : vec){
        sort(genre.second.begin(), genre.second.end(), cmpPair);
        answer.push_back(genre.second[0].second);
        if (genre.second.size() > 1)
            answer.push_back(genre.second[1].second);
    }

    return answer;
}

int main()
{
    vector<string> genres = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> plays = {500,600,150,800,2500};

    vector<int> answer = solution(genres, plays);
    for(int num : answer){
        cout << num << " ";
    }

    return 0;
}