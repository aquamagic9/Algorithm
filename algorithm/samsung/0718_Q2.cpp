#include <iostream>
using namespace std;

bool checkBit(int num, int N){
    for (int i = 0; i < N; i++){
        if (!(num & (1 << i)))
            return false;
    }
    return true;
}

int main()
{
    int T;

    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++){
        int N, M;

        cin >> N >> M;
        cout << "#" << test_case << " ";
        if (checkBit(M, N))
            cout << "ON";
        else
            cout << "OFF";
        cout << "\n";
    }
    return 0;
}