#include <iostream>
using namespace std;

int main()
{
    unsigned int S;
    unsigned int num = 1;
    int N = 0;

    cin >> S;
    while (S > 0)
    {
        if (S >= num)
            S = S - num;
        else
            break;
        num++;
        N++;
    }
    cout << N;

    return 0;
}