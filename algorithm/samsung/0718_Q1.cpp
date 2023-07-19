#include <iostream>
//#include <bitset>
using namespace std;

void collectNum(int &checkNum, int N){
    int tmp = N;

    while(tmp != 0){
        int num = tmp % 10;
        checkNum = checkNum | (1 << num);
        tmp = tmp / 10;
    }
}

//void printBit(int num){
//    cout << bitset<32>(num) << endl;
//}

int main()
{
    int T;

    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++){
        int N;

        cin >> N;
        int multipleN = N;
        int checkNum = 0;
        while(1){
            collectNum(checkNum, multipleN);
            if (checkNum == ((1 << 10) - 1))
                break;
            multipleN += N;
        }
        cout << "#" << test_case << " " << multipleN << "\n";
    }
    return 0 ;
}