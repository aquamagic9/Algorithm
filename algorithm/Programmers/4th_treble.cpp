#include <iostream>
#include <cmath>

using namespace std;

int findCases(int n, int r){
    int result = 0;
    if (n < 3 || 2 * log(n) / log(3) < r)
        return 0;
    if (n == 3)
        return r == 2;
    if (n % 3 == 0 && r >= 2)
        result += findCases(n / 3, r - 2);
    result += findCases(n - 1, r + 1);

    return result;
}

int solution(int n) {
    int answer = findCases(n - 2, 2);

    return answer;
}

int main()
{
    int n = 2147483647; //15, 24, 41, 2147483647

    cout << solution(n) << endl;

    return 0;
}