#include<iostream>
using namespace std;

//시간초과남 나중에 다시하기..
int squareFree(int n)
{
    int cnt = 0;

    for (int i=1;; i++)
    {
        bool isSqFree = true;
        for (int j=2; j*j<=i; j++)
        {
            if (i % (j*j) == 0)
            {
                isSqFree = false;
                break;
            }
        }
        if (isSqFree == true)
        {
            cnt++;
            if (cnt == n)
                return i;
        }
    }
    return 0;
}
int main()
{
    int n = 10;
    cout << squareFree(n) << endl;
    return 0;
}