#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool comp(pair<pair<unsigned int, unsigned int>, int> a, pair<pair<unsigned int, unsigned int>, int> b)
{
    if (a.second > b.second)
        return true;
    return false;
}
int main()
{
    unsigned int start, end;
    vector<pair<unsigned int, unsigned int>> time_table;
    vector<pair<pair<unsigned int, unsigned int>, int>> time_list;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        std::cin >> start >> end;
        time_table.push_back(make_pair(start, end));
    }
    for (int i = 0; i < N; i++)
    {
        int cnt = 0;
        for (int j = 0; j < N; j++)
        {
            if (time_table[i].first < time_table[j].first && time_table[i].second > time_table[j].first
                  || time_table[i].first < time_table[j].second && time_table[i].second > time_table[j].second)
            {
                cnt++;
            }
        }
        time_list.push_back(make_pair(time_table[i], cnt));
    }
    sort(time_list.begin(), time_list.end(), comp);
    for(auto a : time_list)
    {
        cout << a.first.first  << " " << a.first.first << " " << a.second << endl;
    }
    //find max
    vector<pair<unsigned int, unsigned int>> my_time_table;

    for (int i = 0 ; i < N; i++) {
        if (my_time_table.size() == 0) {
            my_time_table.push_back(time_list[i].first);
            continue;
        }
        bool check = false;
        for (int j = 0; j < my_time_table.size(); j++) {
            if (my_time_table[j].first < time_list[i].first.first && my_time_table[j].second > time_list[i].first.first
                || my_time_table[j].first < time_list[i].first.second &&
                   my_time_table[j].second > time_list[i].first.second)
                check = true;
        }
        if (!check) {
            my_time_table.push_back((time_list[i].first));
        }
    }
    cout << my_time_table.size();
    return 0;
}
