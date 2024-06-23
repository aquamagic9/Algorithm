#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;

    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int sIndex = 0, eIndex = n - 1;
    int sum = v[sIndex] + v[eIndex];
    int index1 = sIndex, index2 = eIndex;
    while (sIndex < eIndex){
        int newSum = v[sIndex] + v[eIndex];

        if (abs(sum) > abs(newSum)){
            sum = newSum;
            index1 = sIndex;
            index2 = eIndex;
        }
        if (newSum > 0){
            eIndex--;
        }
        else {
            sIndex++;
        }
    }
    vector<int> resultV;

    resultV.push_back(v[index1]);
    resultV.push_back(v[index2]);
    if (index1 == sIndex || index2 == sIndex){
        int a = 1000000000, b = 1000000000;
        if (index1 - 1 >= 0){
            a = v[index1 - 1];
        }
        if (index2 + 1 < n){
            b = v[index2 + 1];
        }
        if (abs(a) < abs(b)){
            sIndex = index1 - 1;
        }
        else {
            sIndex = index2 + 1;
        }
    }
    resultV.push_back(v[sIndex]);
    sort(resultV.begin(), resultV.end());

    for (int i = 0; i < resultV.size(); i++){
        cout << resultV[i] << " ";
    }

    return 0;
}
// -24 -6 -3 -2 61 98 100