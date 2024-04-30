#include <iostream>

using namespace std;

int main()
{
    int N;
    int result = 0;
    while(cin >> N) {
        int ans = 1;
        result = 1;

        while (true) {
            if (ans % N == 0) {
                break;
            } else {
                ans = ans * 10 + 1;
                ans %= N;
                result++;
            }
        }
        cout << result << "\n";
    }

    return 0;
}