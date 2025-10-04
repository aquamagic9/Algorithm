#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Cell{
    string s;
    vector<Cell*> *listC;
};

vector<string> solution(vector<string> commands) {
    vector<string> answer;

    Cell tmp;
    tmp.listC = nullptr;
    vector<Cell> tRow(51, tmp);
    vector<vector<Cell>> tables(51, tRow);
    int maxI = 0, maxJ = 0;

    for (string command : commands){
        vector<string> c;
        command += ' ';
        while (!command.empty()){
            c.push_back(command.substr(0, command.find(' ')));
            command.erase(0, command.find(' ') + 1);
        }
        if (c[0] == "UPDATE"){
            if (c.size() == 4){
                int row = stoi(c[1]), col = stoi(c[2]);
                maxI = max(maxI, row); maxJ = max(maxJ, col);
                string value = c[3];
                tables[row][col].s = value;
                if (tables[row][col].listC != nullptr){
                    for (auto cell : *tables[row][col].listC){
                        cell->s = value;
                    }
                }
            }
            else if (c.size() == 3){
                string v1 = c[1], v2 = c[2];
                for (int i = 0; i < maxI + 1; i++){
                    for (int j = 0; j < maxJ + 1; j++){
                        if (tables[i][j].s == v1){
                            tables[i][j].s = v2;
                            if (tables[i][j].listC != nullptr){
                                for (auto cell : *tables[i][j].listC){
                                    cell->s = v2;
                                }
                            }
                        }
                    }
                }
            }
        }
        else if (c[0] == "MERGE"){
            int row1 = stoi(c[1]), col1 = stoi(c[2]), row2 = stoi(c[3]), col2 = stoi(c[4]);
            if (row1 == row2 && col1 == col2) continue;
            if (tables[row1][col1].listC == nullptr){
                vector<Cell*> *v = new vector<Cell*>();
                v->push_back(&tables[row1][col1]);
                tables[row1][col1].listC = v;
            }
            if (tables[row2][col2].listC == nullptr){
                vector<Cell*> *v = new vector<Cell*>();
                v->push_back(&tables[row2][col2]);
                tables[row2][col2].listC = v;
            }
            tables[row1][col1].listC->insert(tables[row1][col1].listC->begin(), tables[row2][col2].listC->begin(), tables[row2][col2].listC->end());
            string toStr = !tables[row1][col1].s.empty() ? tables[row1][col1].s : tables[row2][col2].s.empty() ? "" : tables[row2][col2].s;
            vector<Cell*> *list = tables[row1][col1].listC;
            for (auto cell : *list){
                cell->listC = tables[row1][col1].listC;
                cell->s = toStr;
            }
        }
        else if (c[0] == "UNMERGE"){
            int row1 = stoi(c[1]), col1 = stoi(c[2]);
            if (tables[row1][col1].listC == nullptr) continue;
            vector<Cell*> *list = tables[row1][col1].listC;
            string str = tables[row1][col1].s;
            for (auto cell : *list) {
                cell->s.clear();
                cell->listC = nullptr;
            }
            tables[row1][col1].s = str;
        }
        else if (c[0] == "PRINT"){
            int row = stoi(c[1]), col = stoi(c[2]);
            if (!tables[row][col].s.empty()){
                answer.push_back(tables[row][col].s);
            }
            else{
                answer.push_back("EMPTY");
            }
        }
    }

    return answer;
}

int main()
{
    vector<string> commands = {"UPDATE 1 1 menu", "UPDATE 1 2 category", "UPDATE 2 1 bibimbap", "UPDATE 2 2 korean", "UPDATE 2 3 rice", "UPDATE 3 1 ramyeon", "UPDATE 3 2 korean", "UPDATE 3 3 noodle", "UPDATE 3 4 instant", "UPDATE 4 1 pasta", "UPDATE 4 2 italian", "UPDATE 4 3 noodle", "MERGE 1 2 1 3", "MERGE 1 3 1 4", "UPDATE korean hansik", "UPDATE 1 3 group", "UNMERGE 1 4", "PRINT 1 3", "PRINT 1 4"};
    //vector<string> commands = {"UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d", "MERGE 1 1 1 2", "MERGE 1 2 2 2", "PRINT 1 1", "PRINT 1 2", "PRINT 2 2","UNMERGE 1 1" "PRINT 1 1", "PRINT 1 2", "PRINT 2 2"};
    vector<string> answer = solution(commands);
    for (string s : answer)
        cout << s << endl;

    return 0;
}