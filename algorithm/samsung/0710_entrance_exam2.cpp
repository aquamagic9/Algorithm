#include<iostream>
#include<vector>
using namespace std;

void deleteSafeCell(vector<pair<int, int>> &safeCell, bool isRow, int targetIndex){
    if (isRow){
        for(int i = 0;i < safeCell.size(); i++){
            if (safeCell[i].first == targetIndex){
                safeCell.erase(safeCell.begin() + i);
                break;
            }
        }
    }
    else{
        for(int i = 0;i < safeCell.size(); i++){
            if (safeCell[i].second == targetIndex){
                safeCell.erase(safeCell.begin() + i);
                break;
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int T;

    cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)
    {
        int cnt = 0;
        int N, M, Q;

        cin >> N >> M >> Q;
        vector<vector<int>> arr;
        vector<int> rowMax(N, 0), colMax(M, 0);
        vector<pair<int, int>> safeCell;
        for (int i = 0; i < N; i++){
            vector<int> row(M);
            for (int j = 0; j < M; j++){
                cin >> row[j];
                if (row[j] > colMax[j])
                    colMax[j] = row[j];
                if (row[j] > rowMax[i])
                    rowMax[i] = row[j];
            }
            arr.push_back(row);
        }
        for (int i = 0; i < N; i++){
            for (int j = 0; j < M; j++){
                if (rowMax[i] == colMax[j]){
                    safeCell.push_back(make_pair(i, j));
                    break;
                }
            }
        }
        for (int i = 0; i < Q; i++){
            int r, c, x;
            cin >> r >> c >> x;
            r --;
            c --;
            arr[r][c] = x;

            bool isSafeCellRow = false, isSafeCellCol = false;

            if (x > rowMax[r]){
                rowMax[r] = x;
                isSafeCellRow = true;
                deleteSafeCell(safeCell, true, r);
                //cout << "deleteRow: " << r << " " << c << endl;
            }
            if (x > colMax[c]){
                colMax[c] = x;
                isSafeCellCol = true;
                deleteSafeCell(safeCell, false, c);
                //cout << "deleteCow: " << r << " " << c << endl;
            }
            if (isSafeCellRow && isSafeCellCol){
                safeCell.push_back(make_pair(r, c));
                //cout << "Add: " << r << " " << c << endl;
            }
            cnt += safeCell.size();
            //cout << i << "번째 size: " << safeCell.size()<<endl;
        }
        cout << "#" << test_case << " " << cnt << "\n";
    }
    return 0;
}

















//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int cnt = 0;
//
//void safeCellPushBack(vector<vector<int>> &arr, vector<int> &safeCell, int row, int col)
//{
//    safeCell[row] = col;
//    cnt++;
//    for (int i = 0 ; i < safeCell.size(); i++){
//        if (safeCell[i] == col && row != i){
//            if (arr[i][col] < arr[row][col]){
//                safeCell[i] = -1;
//                cnt--;
//            }
//            else{
//                safeCell[row] = -1;
//                cnt--;
//            }
//            return ;
//        }
//    }
//
//    return;
//}
//
//int main(int argc, char** argv)
//{
//    int test_case;
//    int T;
//
//    cin>>T;
//    for(test_case = 1; test_case <= T; ++test_case)
//    {
//        int sumCnt = 0;
//        int N, M, Q;
//
//        cin >> N >> M >> Q;
//        vector<vector<int>> arr;
//        vector<int> safeCell(N, -1);
//        for (int i = 0; i < N; i++){
//            vector<int> row(M);
//            int maxIndex = 0;
//            for (int j = 0; j < M; j++){
//                cin >> row[j];
//                if (row[maxIndex] < row[j])
//                    maxIndex = j;
//            }
//            arr.push_back(row);
//            safeCellPushBack(arr, safeCell, i, maxIndex);
//        }
//        for (int i = 0; i < Q; i++){
//            int r, c, x;
//
//            cin >> r >> c >> x;
//            r --;
//            c --;
//            arr[r][c] = x;
//            if (safeCell[r] == -1){
//                int index = 0;
//                for (int j = 0; j < M; i++){
//                    if ()
//                }
//            }
//            if (arr[r][safeCell[r]] < x){
//                safeCell[r] = c;
//                for (int j = 0; j < safeCell.size(); j++){
//                    if (safeCell[j] == c && j != r){
//                        if (arr[j][safeCell[j]] < arr[r][c]){
//                            safeCell[j] = -1;
//                            cnt--;
//                        } else{
//                            safeCell[r] = -1;
//                            cnt--;
//                        }
//                        break;
//                    }
//                }
//            }
//            else{
//                for (int j = 0; j < safeCell.size(); j++){
//                    if (safeCell[j] == c && j != r){
//                        if (arr[j][safeCell[j]] < arr[r][c]){
//                            safeCell[j] = -1;
//                            cnt--;
//                        }
//                        break;
//                    }
//                }
//            }
//            sumCnt += cnt;
//        }
//        cout << "#" << test_case << " " << sumCnt << "\n";
//    }
//    return 0;
//}