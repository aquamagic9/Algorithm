#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<int> arr(N, 0);
    vector<int> ans(N, 0);
    stack<int> my_stack;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    my_stack.push(0);
    for (int i = 1; i < N; i++){
        while (!my_stack.empty() && arr[my_stack.top()] < arr[i]){
            ans[my_stack.top()] = arr[i];
            my_stack.pop();
        }
        my_stack.push(i);
    }
    while (!my_stack.empty()){
        ans[my_stack.top()] = -1;
        my_stack.pop();
    }
    for(int i = 0; i < N; i++)
        cout << ans[i] << " ";

    return 0;
}