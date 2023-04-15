#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int size = number.size() - k;
    int startind = 0;
    for(int i = 0 ; i < size; i++){
        int max = -1;
        int index = -1;
        for (int j = 0; j < number.size() - k + 1; j++) {
            if (max < number[i + j]) {
                max = number[i + j];
                index = i + j;
            }
        }
        answer += number[index];
        number[index]  = '0';
    }
    return answer;
}

int main()
{
    cout << solution("1924", 2) << endl;
    cout << solution("4177252841", 4) << endl;
    return 0;
}