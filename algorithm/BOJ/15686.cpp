#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Pos{
public:
    int r;
    int c;
    Pos(){
        r = 0;
        c = 0;
    }
    Pos(int r, int c){
        this->r = r;
        this->c = c;
    }
};

template<typename Container_, typename value_type = typename Container_::value_type>
std::vector<std::vector<value_type> > Combination(Container_ container, int r) {
    int n = container.size();
    if (n < r) return {};
    if (r < 0) return {};

    std::vector<std::vector<value_type> >totVec;
    std::vector<value_type> tempVec(r);

    std::vector<bool> v(n);
    std::fill(v.end() - r, v.end(), true);
    int idx;
    do {
        idx = 0;
        for (int i = 0; i < n; ++i) {
            if (v[i]) {
                tempVec[idx++] = *(container.begin() + i);
            }
        }
        totVec.push_back(tempVec);
    } while (std::next_permutation(v.begin(), v.end()));

    return totVec;
}

int main()
{
    int N, M;

    cin >> N >> M;
    vector<vector<int>> arr(N);
    vector<Pos> houses;
    vector<Pos> chickenHouses;
    for (int i = 0; i < N; i++){
        vector<int> row(N);
        for (int j = 0; j < N; j++){
            cin >> row[j];
            if (row[j] == 1){
                houses.push_back(Pos(i, j));
            }
            else if (row[j] == 2){
                chickenHouses.push_back(Pos(i, j));
            }
        }
        arr[i] = row;
    }

    int result = 2147483647;
    for (auto& vec : Combination(chickenHouses, M)) {
        int sum = 0;
        for (int i = 0; i < houses.size(); i++){
            int minDistance = N + N;
            for (auto &ele: vec) {
                int d = abs(houses[i].r - ele.r) + abs(houses[i].c - ele.c);
                if (minDistance > d){
                    minDistance = d;
                }
            }
            sum += minDistance;
        }
        result = min(result, sum);
    }
    cout << result;

    return 0;
}