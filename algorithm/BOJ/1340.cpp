#include <iostream>
#include <string>
using namespace std;
string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
    string s;

    getline(cin, s);

    string front = s.substr(0, s.find(','));
    string month = front.substr(0, front.find(' '));
    string day = front.substr(front.find(' ') + 1);
    string back = s.substr(s.find(',') + 2);
    string year = back.substr(0, back.find(' ') + 1);
    string time = back.substr(back.find(' ') + 1);
    int hour = stoi(time.substr(0,time.find(':')));
    int minute = stoi(time.substr(time.find(':') + 1));

    long double totalTimeInYear = 0;
    long double currentTime = 0;
    for (int i = 0; i < 12; i++){
        totalTimeInYear += days[i] * 24 * 60;
        if (i == 1 && (stoi(year) % 400 == 0 || (stoi(year) % 4 == 0 && stoi(year) % 100 != 0) )){
            totalTimeInYear += 24 * 60;
        }
    }
    for (int i = 0 ; i < 12; i++){
        if (month == months[i]){
            currentTime += (stoi(day) - 1) * 24 * 60;
            break;
        }
        currentTime += days[i] * 24 * 60;
        if (i == 1 && (stoi(year) % 400 == 0 || (stoi(year) % 4 == 0 && stoi(year) % 100 != 0) )){
            currentTime += 24 * 60;
        }
    }
    currentTime += hour * 60 + minute;

    fixed(cout);
    cout.precision(15);
    cout << currentTime / totalTimeInYear * 100;


    return 0;
}