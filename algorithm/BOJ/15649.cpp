#include <iostream>
#include <list>
using namespace std;

void SelectNum(list<int> numList, int seatCount, string num);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    string num;

    cin >> N >> M; // 1 <= M <= N <= 8

    list<int> NList;
    for (int i = 1; i <= N; i++)
        NList.push_back(i);

    SelectNum(NList, M, num);

    return 0;
}

void SelectNum(list<int> numList, int seatCount, string num)
{
    if (seatCount == 0)
    {
        cout << num << "\n";
        return ;
    }
    for (list<int>::iterator iter = numList.begin(); iter != numList.end(); iter++)
    {
        list<int> tmp(numList);
        tmp.remove(*iter);
        SelectNum(tmp, seatCount - 1, num + to_string(*iter) + " ");
    }
}