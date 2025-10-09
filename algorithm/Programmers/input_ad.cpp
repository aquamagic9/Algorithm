#include <string>
#include <vector>
#include <iostream>

using namespace std;

int timeToInt(string s, char c){
    vector<string> strs;

    s += c;
    while (!s.empty()){
        strs.push_back(s.substr(0, s.find(c)));
        s.erase(0, s.find(c) + 1);
    }

    return stoi(strs[0]) * 60 * 60 + stoi(strs[1]) * 60 + stoi(strs[2]);
}

string timeToString(int n){
    string sec = to_string(n % 60);
    if (sec.size() == 1)
        sec = "0" + sec;
    n /= 60;
    string min = to_string(n % 60);
    if (min.size() == 1)
        min = "0" + min;
    n /= 60;
    string hour = to_string(n);
    if (hour.size() == 1)
        hour = "0" + hour;

    return hour + ":" + min + ":" + sec;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    int playTimeInt = timeToInt(play_time, ':');
    int adv_timeInt = timeToInt(adv_time, ':');
    vector<long long> vec(playTimeInt + 1, 0);

    for (string log : logs){
        int start = timeToInt(log.substr(0, play_time.length()), ':');
        int end = timeToInt(log.substr(log.find('-') + 1, play_time.length()), ':');
        vec[start] += 1;
        vec[end] -= 1;
    }

    for (int i = 0; i < playTimeInt; i++){
        vec[i + 1] += vec[i];
    }
    for (int i = 0; i < playTimeInt; i++){
        vec[i + 1] += vec[i];
    }

    long long maxValue = vec[adv_timeInt - 1], adStartTime = 0;
    for (int i = 1; i <= playTimeInt; i++){
        if (i + adv_timeInt - 1 <= playTimeInt && vec[i + adv_timeInt - 1] - vec[i - 1] > maxValue){
            maxValue = vec[i + adv_timeInt - 1] - vec[i - 1];
            adStartTime = i;
        }
    }
    answer = timeToString(adStartTime);

    return answer;
}

int main()
{
    string play_time = "02:03:55";
    string adv_time = "00:14:15";
    vector<string> logs = {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"};

    cout << solution(play_time, adv_time, logs);

    return 0;
}