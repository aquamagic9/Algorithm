#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N, sum = 0;
    string quiz;

    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> quiz;
        int accumulation = 0;
        sum = 0;
        for (int j = 0; j < quiz.length(); j++){
            if (quiz[j] == 'O')
                sum += ++accumulation;
            else
                accumulation = 0;
        }
        cout << sum << "\n";
    }

    return 0;
}