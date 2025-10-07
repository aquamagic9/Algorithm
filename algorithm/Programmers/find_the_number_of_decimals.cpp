#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int isPrime(long long n){
    if (n == 1)
        return false;
    for (long long i = 2; i <= sqrt(n); i++){
        if (n % i == 0)
            return false;
    }
    return true;
}

string toKDecimal(int n, int k){
    string kDecimal = "";
    while (n > 0){
        kDecimal = to_string(n % k) + kDecimal;
        n /= k;
    }
    return kDecimal;
}

int solution(int n, int k) {
    int answer = 0;

    string kDecimal = toKDecimal(n, k);
    kDecimal += "0";
    vector<string> splitK;
    while (!kDecimal.empty()){
        string s = kDecimal.substr(0, kDecimal.find('0'));
        if (!s.empty())
            splitK.push_back(s);
        kDecimal.erase(0, kDecimal.find('0') + 1);
    }

    for (auto &numS : splitK){
        if (isPrime(stoll(numS))){
            answer++;
            //cout << numS << endl;
        }
    }

    return answer;
}

int main()
{
    int n = 10011, k = 10;

    int result = solution(n, k);
    cout << "result:" << result << endl;

    return 0;
}