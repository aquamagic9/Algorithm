#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> splitStr(string s, char c){
    vector<string> splittedStrs;
    s += c;
    while (!s.empty()){
        splittedStrs.push_back(s.substr(0, s.find(c)));
        s.erase(0, s.find(c) + 1);
    }
    return splittedStrs;
}

int stringTimeToInt(string s){
    vector<string> time = splitStr(s, ':');
    return stoi(time[0]) * 60 + stoi(time[1]);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    int baseTime = fees[0], baseFee = fees[1], unitTime = fees[2], unitFee = fees[3];

    map<string, vector<int>> carInfo;
    for (string s : records){
        vector<string> splitS = splitStr(s, ' ');
        carInfo[splitS[1]].push_back(stringTimeToInt(splitS[0]));
    }

    for (auto &car : carInfo){
        int sum = 0, sumTime = 0;
        vector<int> &inOutTimes = car.second;
        for (int i = 0; i < inOutTimes.size() - 1; i += 2){
            sumTime += inOutTimes[i + 1] - inOutTimes[i];
        }
        if (inOutTimes.size() % 2){
            sumTime += stringTimeToInt("23:59") - inOutTimes[inOutTimes.size() - 1];
        }
        //cout << car.first << " " << sum << endl;
        if (sumTime - baseTime > 0){
            sum = unitFee * ((sumTime - baseTime) / unitTime + (((sumTime - baseTime) % unitTime) != 0));
        }
        sum += baseFee;
        answer.push_back(sum);
    }

    return answer;
}

int main()
{
    //vector<int> fee = {180, 5000, 10, 600};
    //vector<string> records = {"05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"};

    vector<int> fee = {120, 0, 60, 591};
    vector<string> records = {"16:00 3961 IN","16:00 0202 IN","18:00 3961 OUT","18:00 0202 OUT","23:58 3961 IN"};



    vector<int> results = solution(fee, records);
    for (int k : results){
        cout << k << endl;
    }

    return 0;
}