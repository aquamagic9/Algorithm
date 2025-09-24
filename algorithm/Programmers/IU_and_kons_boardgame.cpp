#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int crossProduct(vector<int> v1, vector<int> v2)
{
    return v1[0] * v2[1] - v1[1] * v2[0];
}

//float dotProduct(vector<int> v1, vector<int> v2)
//{
//    return v1[0] * v2[0] + v1[1] * v2[1];
//}
//
//float vectorRelevance(vector<int> v1, vector<int> v2)
//{
//    return dotProduct(v1, v2) / sqrt(v1[0] * v1[0] + v1[1] * v1[1]) / sqrt(v2[0] * v2[0] + v2[1] * v2[1]);
//}

//연결 가능한 점인지 확인.(외적으로 판별)
bool condition1(vector<int> v1, vector<int> v2, vector<int> v3)
{
    if (crossProduct(v1, v2) < 0 && crossProduct(v2, v3) < 0)
        return true;
    return false;
}

//제거 조건
bool condition2(vector<int> d, vector<int> c1, vector<int> c2, vector<int> t)
{
    vector<int> v1 = {c2[0] - c1[0], c2[1] - c1[1]};
    vector<int> v2 = {d[0] - c1[0], d[1] - c1[1]};
    vector<int> v3 = {t[0] - c2[0], t[1] - c2[1]};
    vector<int> v4 = {d[0] - c2[0], d[1] - c2[1]};
    vector<int> v5 = {c1[0] - t[0], c1[1] - t[1]};
    vector<int> v6 = {d[0] - t[0], d[1] - t[1]};

    if (crossProduct(v1, v2) < 0 && crossProduct(v3, v4) < 0 && crossProduct(v5, v6) < 0)
        return true;
    return false;
}

bool condition3(vector<int> tp, vector<int> sp, vector<int> lp)
{
    vector<int> v1 = {lp[0] - tp[0], lp[1] - tp[1]};
    vector<int> v2 = {sp[0] - tp[0], sp[1] - tp[1]};

    return crossProduct(v1, v2) < 0;
}

vector<vector<int>> eraseDots(const vector<vector<int>> &v, const vector<int> &c1, const vector<int> &c2, const vector<int> &t)
{
    vector<vector<int>> newV;

    for(auto d : v){
        if (condition2(d, c1, c2, t) || d == c2){
            continue;
        }
        newV.push_back(d);
    }
    return newV;
}

void makePinTriangle(vector<vector<int>> triangle, vector<vector<int>> v, vector<int> ds, vector<int> lv, int& answer, vector<vector<int>> list){
    list.push_back(ds);
    if (triangle.size() == 1){
        if (list.size() >= 6 && !condition3(triangle[0], list[1], list[list.size() - 2])){
            return;
        }
        if (v.size() == 0){
            answer++;
            cout << endl;
            for (auto l : list)
                cout << "listDot: " << l[0] << " " << l[1] << endl;
            cout << "vsize: " << v.size() << endl;
            cout << "answer: " << answer << endl;
        }
        return;
    }

    vector<vector<int>> newTriangle(triangle.size() - 1);
    copy(triangle.begin() + 1, triangle.end(), newTriangle.begin());
    //삼각형의 다음 꼭지점을 기준으로 시작.
    makePinTriangle(newTriangle, v, newTriangle[0],{ds[0] - newTriangle[0][0], ds[1] - newTriangle[0][1]} ,answer, list);

    for (auto dot : v){
        vector<int> dv = {dot[0] - ds[0], dot[1] - ds[1]};
        vector<int> l2v = {triangle[1][0] - ds[0], triangle[1][1] - ds[1]};
        //연결 가능 점이면
        if(condition1(lv, dv, l2v)){
            //cout << "[dot: " << dot[0] << " " << dot[1] << "] [ds: " << ds[0] << " " << ds[1] << "] [t: " << triangle[1][0] << " " << triangle[1][1] << "]" <<endl;
            //cout << "[lv: " << lv[0] << " " << lv[1] << "] [dv: " << dv[0] << " " << dv[1] << "] [l2v: " << l2v[0] << " " << l2v[1] << "]" <<endl;

            //점들을 삭제하고 남은점들
            vector<vector<int>> newV = eraseDots(v, ds, dot, triangle[1]);
            vector<int> newLV = {dot[0] - ds[0], dot[1] - ds[1]};
            makePinTriangle(triangle, newV, dot,newLV,answer, list);
        }
    }

    return;
}

int solution(int n, vector<vector<int>> triangle, vector<vector<int>> v) {
    int answer = 0;

    //삼각형 첫번째점을 마지막에 넣기
    triangle.push_back(triangle[0]);
    vector<int> lv = {triangle[2][0] - triangle[0][0], triangle[2][1] - triangle[0][1]};

    vector<vector<int>> list;
    makePinTriangle(triangle, v, triangle[0], lv, answer, list);

    return answer;
}

int main()
{
    vector<vector<int>> triangle = {{0,8},{-4,0},{4,0}};
    vector<vector<int>> v = {{-1,3},{1,4}};

    vector<vector<int>> triangle2 = {{-13, 40}, {-27, -48}, {31, 6}};
    vector<vector<int>> v2 = {{2, 21}, {15, -1}, {6, -13}, {-20, -27}, {5, 9}, {5, 11}, {-18, -26}, {-15, 19}, {7, 4}, {-5, -18}};
    //vector<vector<int>> v3 = {{6, -13}, {-20, -27}, {5, 11}, {-18, -26}};
    vector<vector<int>> v4 = {{7, 4}, {6, -13}, {15, -1}, {5, 9}, {5, 11}};
    vector<vector<int>> v5  = {{2,21}, {15, - 1}, {6, -13}};


    int answer = solution(2, triangle2, v2);

    cout << "myAnswer: " << answer << endl;

    return 0;
}