#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> v;
int DivisionOfConstituencies(int x, int y, int d1, int d2);

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vector<int> row(N);
        for (int j = 0; j < N; j++)
        {
            cin >> row[j];
        }
        v.push_back(row);
    }

    int minValue = INT32_MAX;
    for (int x = 0; x < N; x++){
        for (int y = 0; y < N; y++){
            for (int d1 = 1; d1 < N; d1++){
                for (int d2 = 1; d2 < N; d2++){
                    if ((x + d1 + d2) < N && y - d1 >= 0 && y + d2 < N){
                        int result = DivisionOfConstituencies(x, y, d1, d2);
                        //cout << result << " x: " << x << " y: " << y << " d1: " << d1 << " d2: " << d2 << endl << endl;
                        minValue = min(minValue, result);
                    }
                }
            }
        }
    }
    cout << minValue;

    return 0;
}

int DivisionOfConstituencies(int x, int y, int d1, int d2)
{
    vector<int> numberOfPeopleConstituency(6, 0);
    vector<vector<int>> visit;
    for (int i = 0; i < N; i++){
        vector<int> tmp(N, 0);
        visit.push_back(tmp);
    }

    //5구간
    int start = y;
    int end = y;
    for (int r = x; r <= x + d1 + d2; r++){
        if (r != x){
            start = (r > x + d1) ? start + 1 : start - 1;
            end = (r > x + d2) ? end - 1 : end + 1;
        }
        for (int c = start; c <= end; c++){
            visit[r][c] = 1;
            numberOfPeopleConstituency[5] += v[r][c];
        }
    }
    //1구간
    for (int r = 0; r < x + d1; r++){
        for (int c = 0; c <= y; c++){
            if (visit[r][c] != 1){
                visit[r][c] = 1;
                numberOfPeopleConstituency[1] += v[r][c];
            }
        }
    }
    //2구간
    for (int r = 0; r <= x + d2; r++){
        for (int c = y + 1; c < N; c++){
            if (visit[r][c] != 1){
                visit[r][c] = 1;
                numberOfPeopleConstituency[2] += v[r][c];
            }
        }
    }
    //3구간
    for (int r = x + d1; r < N; r++){
        for (int c = 0; c < y - d1 + d2; c++){
            if (visit[r][c] != 1){
                visit[r][c] = 1;
                numberOfPeopleConstituency[3] += v[r][c];
            }
        }
    }
    //4구간
    for (int r = x + d2 + 1; r < N; r++){
        for (int c = y - d1 + d2; c < N; c++){
            if (visit[r][c] != 1){
                visit[r][c] = 1;
                numberOfPeopleConstituency[4] += v[r][c];
            }
        }
    }
    int minValue = numberOfPeopleConstituency[1];
    int maxValue = numberOfPeopleConstituency[1];
    for (int i = 1; i <= 5; i++){
        minValue = min(minValue, numberOfPeopleConstituency[i]);
        maxValue = max(maxValue, numberOfPeopleConstituency[i]);
    }
    return maxValue - minValue;
}