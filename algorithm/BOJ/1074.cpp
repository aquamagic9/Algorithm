#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int N, r, c;

    cin >> N >> r >> c;

    long int result = 0;
    while (N != 1){
        int width = pow(2, N);
        int height = pow(2, N);
        int quarter = pow(2, N + N - 2);
        N--;
        if (r >= 0 && r < height / 2  && c >= 0 && c < width / 2){
            continue;
        }
        if (r >= height / 2 && r < height){
            result += quarter * 2;
            r = r - height / 2;
        }
        if (c >= width / 2 && c < width){
            result += quarter;
            c = c - width / 2;
        }
    }
    result += r * 2 + c;
    cout << result;

    return 0;
}