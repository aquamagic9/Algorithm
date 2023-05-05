#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    long long a = 2;
    long long b = 1;
    int i = 0;

    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    while (i < n - 2)
    {
        answer = (a + b)  % 1234567;
        b = a;
        a = answer;
        i++;
    }
    return answer;
}