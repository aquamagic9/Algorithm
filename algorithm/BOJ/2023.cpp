#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num)
{
    for (int i = 2; i <= num/2; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}
void dfs(int num, int number_of_digit, int N){
    if (number_of_digit == N && isPrime(num))
    {
        cout << num << "\n";
        return;
    }
    for (int i = 1; i <= 9; i+=2){
        if (isPrime(num * 10 + i))
            dfs(num*10 + i, number_of_digit + 1, N);
    }

}
int main()
{
    int N;

    cin >> N;
    dfs(2, 1, N);
    dfs(3, 1, N);
    dfs(5, 1, N);
    dfs(7, 1, N);
    return 0;
}