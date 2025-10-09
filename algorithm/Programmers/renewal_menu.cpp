#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> courseSize;
void combination(string &s, string newCourse, int r, int cnt, int index, map<string, int> &Courses){
    if (cnt == r){
        Courses[newCourse]++;
        courseSize[r] = max(courseSize[r], Courses[newCourse]);
        return ;
    }
    if (s.length() <= index)
        return ;
    combination(s, newCourse + s[index], r, cnt + 1, index + 1, Courses);
    combination(s, newCourse, r, cnt, index + 1, Courses);
    return ;
}

vector<string> makeCourses(vector<string> &orders, vector<int> &course) {
    map<string, int> Courses;
    for (string order : orders){
        sort(order.begin(), order.end());
        for (int n : course){
            if (order.length() >= n){
                combination(order, "", n, 0, 0, Courses);
            }
        }
    }

    vector<string> newCourses;
    for (int n : course){
        int maxCnt = 0;
        for (auto newCourse : Courses){
            if (newCourse.first.length() == n && courseSize[n] == newCourse.second && courseSize[n] >= 2){
                newCourses.push_back(newCourse.first);
            }
        }
        sort(newCourses.begin(), newCourses.end());
    }

    return newCourses;
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    courseSize.assign(11, 0);
    answer = makeCourses(orders, course);

    return answer;
}

int main()
{
    vector<string> orders = {"ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"};
    vector<int> course = {2,3,4};

    vector<string> result = solution(orders, course);
    for (string s : result){
        cout << s << " " << endl;
    }

    return 0;
}