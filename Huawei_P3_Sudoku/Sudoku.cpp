/*
Input:
0 9 5 0 2 0 0 6 0
0 0 7 1 0 3 9 0 2
6 0 0 0 0 5 3 0 4
0 4 0 0 1 0 6 0 7
5 0 0 2 0 7 0 0 9
7 0 3 0 9 0 0 2 0
0 0 9 8 0 0 0 0 6
8 0 6 3 0 2 1 0 5
0 5 0 0 7 0 2 8 3
*/
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <queue>
using namespace std;

void InitPossibleValue(vector<vector<int> > &sudoku, 
    map<int, set<int> > &possible_value);

int FindOnlyPossible(map<int, set<int> > &possible_value);

void RefreshRow(int value, vector<vector<int> > &sudoku, 
    map<int, set<int> > &possible_value, queue<int> &BFS);

void RefreshColumn(int value, vector<vector<int> > &sudoku, 
    map<int, set<int> > &possible_value, queue<int> &BFS);

void RefreshSquare(int value, vector<vector<int> > &sudoku, 
    map<int, set<int> > &possible_value, queue<int> &BFS);

int main() {
    vector<vector<int> > sudoku;
    map<int, set<int> > possible_value;
    queue<int> BFS;
    for (int i = 0; i < 9; i++) {
        vector<int> input_line;
        for (int j = 0; j < 9; j++) {
            int input;
            cin >> input;
            input_line.push_back(input);
        }
        sudoku.push_back(input_line);
    }
    InitPossibleValue(sudoku, possible_value);
    int found = FindOnlyPossible(possible_value);
    while (found != -1) {
        BFS.push(found);
        while (!BFS.empty()) {
            int top_value = BFS.front();
            BFS.pop();
            RefreshRow(top_value, sudoku, possible_value, BFS);
            RefreshColumn(top_value, sudoku, possible_value, BFS);
            RefreshSquare(top_value, sudoku, possible_value, BFS);
        }
        found = FindOnlyPossible(possible_value);
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j];
            if (j != 8) {
                cout << " ";
            }
        }
        cout << endl;
    }
}

void InitPossibleValue(vector<vector<int>>& sudoku, 
    map<int, set<int>>& possible_value) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) {
                for (int k = 1; k <= 9; k++) {
                    possible_value[i * 9 + j].insert(k);
                }
                //Row
                for (int k = 0; k < 9; k++) {
                    if (possible_value[i * 9 + j].count(sudoku[i][k]) != 0) {
                        possible_value[i * 9 + j].erase(sudoku[i][k]);
                    }
                }
                //Column
                for (int k = 0; k < 9; k++) {
                    if (possible_value[i * 9 + j].count(sudoku[k][j]) != 0) {
                        possible_value[i * 9 + j].erase(sudoku[k][j]);
                    }
                }
                //Square
                int i_search = i, j_search = j;
                for (int k = 0; k < 9; k++) {
                    if (++j_search >= (j / 3 + 1) * 3) {
                        j_search -= 3;
                        if (++i_search >= (i / 3 + 1) * 3) {
                            i_search -= 3;
                        }
                    }
                    if (possible_value[i * 9 + j].count(sudoku[i_search][j_search]) != 0) {
                        possible_value[i * 9 + j].erase(sudoku[i_search][j_search]);
                    }
                }
            }
        }
    }
}

int FindOnlyPossible(map<int, set<int>>& possible_value) {
    for (auto itr = possible_value.begin(); itr != possible_value.end(); ++itr) {
        if (itr->second.size() == 1) {
            return itr->first;
        }
    }
    return -1;
}

void RefreshRow(int value, vector<vector<int>>& sudoku, 
    map<int, set<int>>& possible_value, queue<int>& BFS) {

    int i = value / 9, j = value % 9;
    if (sudoku[i][j] == 0) {
        sudoku[i][j] = *possible_value[value].begin();
        possible_value.erase(value);
    }
    for (int k = 0; k < 9; k++) {
        if (possible_value.count(i * 9 + k) != 0) {
            possible_value[i * 9 + k].erase(sudoku[i][j]);
            if (possible_value[i * 9 + k].size() == 1) {
                BFS.push(i * 9 + k);
            }
        }
    }
}

void RefreshColumn(int value, vector<vector<int>>& sudoku, 
    map<int, set<int>>& possible_value, queue<int>& BFS) {

    int i = value / 9, j = value % 9;
    if (sudoku[i][j] == 0) {
        sudoku[i][j] = *possible_value[value].begin();
        possible_value.erase(value);
    }
    for (int k = 0; k < 9; k++) {
        if (possible_value.count(k * 9 + j) != 0) {
            possible_value[k * 9 + j].erase(sudoku[i][j]);
            if (possible_value[k * 9 + j].size() == 1) {
                BFS.push(k * 9 + j);
            }
        }
    }

}

void RefreshSquare(int value, vector<vector<int>>& sudoku, 
    map<int, set<int>>& possible_value, queue<int>& BFS) {

    int i = value / 9, j = value % 9;
    if (sudoku[i][j] == 0) {
        sudoku[i][j] = *possible_value[value].begin();
        possible_value.erase(value);
    }
    int i_search = i, j_search = j;
    for (int k = 0; k < 9; k++) {
        if (++j_search >= (j / 3 + 1) * 3) {
            j_search -= 3;
            if (++i_search >= (i / 3 + 1) * 3) {
                i_search -= 3;
            }
        }
        if (possible_value.count(i_search * 9 + j_search) != 0) {
            possible_value[i_search * 9 + j_search].erase(sudoku[i][j]);
            if (possible_value[i_search * 9 + j_search].size() == 1) {
                if (i_search != i && j_search != j) {
                    BFS.push(i_search * 9 + j_search);
                }
            }
        }
    }
}

