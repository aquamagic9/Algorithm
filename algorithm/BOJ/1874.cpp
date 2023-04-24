#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    int N;
    stack<int> my_stack;

    cin >> N;
    vector<int> arr(N, 0);
    vector<char> resultV;

    for (int i = 0; i < N; i++){
        cin >> arr[i];
    }

    int num = 1;
    bool result = true;
    for (int i = 0; i < arr.size(); i++){
        int su = arr[i];
        if (su >= num){
            while (su >= num){
                my_stack.push(num++);
                resultV.push_back('+');
            }
            my_stack.pop();
            resultV.push_back('-');
        }
        else{
            int n = my_stack.top();
            my_stack.pop();
            if (n > su){
                cout << "NO";
                result = false;
                break;
            }
            else{
                resultV.push_back('-');
            }
        }
    }
    if (result){
        for (int i = 0 ; i < resultV.size(); i++){
            cout << resultV[i] << "\n";
        }
    }
    return 0;
}