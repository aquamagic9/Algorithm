#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long double x, y, c, result;

    cin >> x >> y >> c;

    long double low, high;
    low = 0;
    high = min(x, y);

    long double mid, h1, h2, tmpC;
    while (high - low > 0.0001){
        mid = (low + high) / 2;
        h1 = sqrt(x*x - mid*mid);
        h2 = sqrt(y*y - mid*mid);
        tmpC = (h1 * h2) / (h1 + h2);

        if (tmpC > c){
            low = mid;
        }
        else{
            high = mid;
        }
        result = mid;
    }
    fixed(cout);
    cout.precision(3);
    cout << result;

    return 0;
}