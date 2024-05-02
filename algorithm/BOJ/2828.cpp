#include <iostream>
using namespace std;

int main()
{
    int N, M, J;

    cin >> N >> M >> J;
    int basketFirstPos = 1;

    int pos, d = 0;
    for (int i = 0; i < J; i++)
    {
        cin >> pos;
        int distance;
        if (pos >= basketFirstPos + M){
            distance = pos - (basketFirstPos + M) + 1;
            d += distance;
            basketFirstPos += distance;
        }
        else if (pos < basketFirstPos){
            distance = basketFirstPos - pos;
            d += distance;
            basketFirstPos -= distance;
        }
    }
    cout << d;

    return 0;
}