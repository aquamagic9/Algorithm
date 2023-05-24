#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> triangle(3);
    int sum = 0;
    for (int i = 0; i < 3; i++){
        cin >> triangle[i];
        sum += triangle[i];
    }
    if (sum == 180){
        if (triangle[0] == triangle[1] && triangle[1] == triangle[2])
            cout << "Equilateral";
        else if (triangle[0] == triangle[1] || triangle[1] == triangle[2] || triangle[0] == triangle[2])
            cout << "Isosceles";
        else
            cout << "Scalene";
    } else
        cout << "Error";
    return 0;
}