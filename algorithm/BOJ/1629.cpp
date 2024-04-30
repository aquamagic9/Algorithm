#include <iostream>
using namespace std;

int A,B,C;
long long f(long long y) {
    if (y == 1)
        return A % C;

    long long k = f(y/2);
    if (y % 2)
        return k % C * k % C * A % C;
    return k % C * k % C;
}
int main()
{
    cin >> A >> B >> C;

    cout << f(B);

    return 0;
}