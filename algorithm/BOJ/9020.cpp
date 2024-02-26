#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int primeNumber[10001];

bool isPrimeNumber(int num)
{
    int k = 1, cnt = 1;

    if (primeNumber[num] != -1){
        return primeNumber[num] == 1;
    }
    while (k <= sqrt(num)){
        if (num % k == 0){
            cnt++;
        }
        k++;
    }
    if (cnt == 2){
        primeNumber[num] = 1;
        return true;
    }
    primeNumber[num] = 0;
    return false;
}

int main()
{
    int T, N;

    cin >> T;
    memset(primeNumber, -1, sizeof(primeNumber));
    for (int i = 0; i < T; i++){
        cin >> N;
        int num = N / 2;
        while (num != 1){
            if (isPrimeNumber(num) && isPrimeNumber(N - num)){
                cout << num << " " << N - num << "\n";
                break;
            }
            num--;
        }
    }

    return 0;
}