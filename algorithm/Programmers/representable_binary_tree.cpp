#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string numToBinaryString(long long numbers){
    string s1 = "";

    int n = 1, strLength = 1;
    while (numbers >= pow(2, strLength)){
        n *= 2;
        strLength += n;
    }

    int k = log(numbers) / log(2) + 1;
    for (int i = 0; i < strLength - k; i++)
        s1 += "0";

    string s2 = "";
    while (numbers > 0){
        s2 = numbers % 2 ? "1" + s2 : "0" + s2;
        numbers /= 2;
    }

    return s1 + s2;
}

bool checkRepresentableBinaryTree(string s){
    if (s.size() == 1)
        return true;

    if (s[s.size() / 2] == '0')
        if (s[s.size() / 4] == '1'|| s[s.size() / 2 + 1 + s.size() / 4] == '1')
            return false;

    bool cl = checkRepresentableBinaryTree(s.substr(0, s.size() / 2));
    bool cr = checkRepresentableBinaryTree(s.substr(s.size() / 2 + 1, s.size() / 2));

    return cl && cr;
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (long long n : numbers)
        checkRepresentableBinaryTree(numToBinaryString(n)) ? answer.push_back(1) : answer.push_back(0);

    return answer;
}

int main()
{
    //vector<long long> numbers = {7, 42, 5};
    //vector<long long> numbers = {63, 111, 95, 3712, 16};
    vector<long long> numbers = {130};

    vector<int> answer = solution(numbers);
    for (int n : answer){
        cout << n << " ";
    }

    return 0;
}