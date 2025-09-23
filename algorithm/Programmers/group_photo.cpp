#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct condition{
    char c1;
    char c2;
    char sign;
    int num;
};

bool check(const vector<condition> &conditions, const vector<int> &nums, const vector<char> &friends){
    bool can = true;
    for (auto con : conditions){
        int p1 = -1, p2 = -1;

        for (int i = 0; i < nums.size(); i++){
            if (friends[nums[i]] == con.c1)
                p1 = i;
            if (friends[nums[i]] == con.c2)
                p2 = i;
        }

        bool can_con = false;
        int d = abs(p2 - p1) - 1;

        if (con.sign == '=' && d == con.num) can_con = true;
        if (con.sign == '<' && d < con.num) can_con = true;
        if (con.sign == '>' && d > con.num) can_con = true;

        can &= can_con;
    }

    return can;
}

int solution(int n, vector<string> data) {
    int answer = 0;
    vector<condition> conditions;
    vector<int> nums = {0,1,2,3,4,5,6,7};
    vector<char> friends = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

    for (string d : data){
        condition con;

        con.c1 = d[0]; con.c2 = d[2]; con.sign = d[3]; con.num = d[4] - '0';
        conditions.push_back(con);
    }

    do{
        if (check(conditions, nums, friends)){
            answer++;
        }
    }while(next_permutation(nums.begin(), nums.end()));

    return answer;
}

int main()
{
    int n = 2;
    vector<string> data = {"N~F=0", "R~T>2"};
    vector<string> data2 = {"M~C<2", "C~M>1"};
    vector<string> data3 = {"M~C=6"};

    cout << solution(n, data3);

    return 0;
}