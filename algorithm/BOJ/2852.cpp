#include <iostream>
using namespace std;

string timeToString(int time){
    string minutes, seconds;

    minutes = to_string(time / 60);
    if (minutes.size() == 1){
        minutes = "0" + minutes;
    }
    seconds = to_string(time % 60);
    if (seconds.size() == 1){
        seconds = "0" + seconds;
    }
    return minutes + ":" + seconds;
}

int main()
{
    int N;

    cin >> N;
    int score1 = 0, score2 = 0, checkTime = 0, team1Time = 0, team2Time = 0;
    for (int i = 0; i <= N; i++){
        int teamNum, timeBySeconds;
        string time;
        if (i != N)
            cin >> teamNum >> time;
        else{
            teamNum = -1;
            time = "48:00";
        }
        timeBySeconds = stoi(time.substr(0,2)) * 60 + stoi(time.substr(3, 2));
        if (score1 > score2){
            team1Time += timeBySeconds - checkTime;
        }
        else if (score1 < score2){
            team2Time += timeBySeconds - checkTime;
        }
        if (teamNum == 1){
            score1++;
        }
        else if (teamNum == 2){
            score2++;
        }
        checkTime = timeBySeconds;
    }
    cout << timeToString(team1Time) << "\n";
    cout << timeToString(team2Time) << "\n";

    return 0;
}