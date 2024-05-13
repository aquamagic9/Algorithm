#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<char> inequality;
int v[10] = {0, 1, 2, 3,4,5,6,7,8,9};
string minResult, maxResult;
long long minValue = 9876543210, maxValue = 0;
int k;

string makeValue(int r){
    string newValue = "";
    for (int i = 0; i < r; i++){
        newValue += to_string(v[i]);
    }
    return newValue;
}

bool checkCondition()
{
    for(int i = 0; i < k; i++){
        if (inequality[i] == '<' && v[i] < v[i + 1] || inequality[i] == '>' && v[i] > v[i + 1]){
            continue;
        }
        return false;
    }
    return true;
}

void makePermutation(int n, int r, int depth)
{
    if (depth == r && checkCondition()){
        string sValue = makeValue(r);
        long long value = stoll(sValue);
        if (value > maxValue){
            maxValue = value;
            maxResult = sValue;
        }
        if (value < minValue){
            minValue = value;
            minResult = sValue;
        }
        return;
    }
    for (int i = depth; i < n; i++)
    {
        swap(v[i], v[depth]);
        makePermutation(n, r, depth + 1);
        swap(v[i], v[depth]);
    }
    return ;
}

int main()
{
    cin >> k;
    inequality.resize(k);
    for (int i = 0; i < k; i++){
        cin >> inequality[i];
    }
    makePermutation(10, k+1, 0);
    cout << maxResult << "\n" << minResult;

    return 0;
}