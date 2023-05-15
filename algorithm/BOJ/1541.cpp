#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string input, char delimiter){
    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    while (getline(mystream, splitdata, delimiter)){
        result.push_back(splitdata);
    }
    return result;
}

int main()
{
    string form;
    vector<string> result;
    int sum = 0;

    cin >> form;
    result = split(form,'-');
    for (int i = 0; i < result.size(); i++){
        vector<string> sub_plus = split(result[i],'+');
        int sub_sum = 0;
        for (int j = 0; j < sub_plus.size(); j++)
            sub_sum += stoi(sub_plus[j]);
        if (i == 0){
            sum += sub_sum;
        } else{
            sum -= sub_sum;
        }
    }
    cout << sum;

    return 0;
}