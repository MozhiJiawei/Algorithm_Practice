/*
2
........
........
........
...*o...
...o*...
........
........
........
4
3 5 0
2 5 1
2 4 0
4 5 1
ooo.....
ooo.....
*ooooooo
.oooooo*
...oo..o
........
........
........
3
1 7 0
0 7 1
3 0 1
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> board(8, vector<char>(8, '.'));
 void GetClear(int x, int y, int k, int step_down, int step_right) { 
     int step = 0;
     char cur, opp;
     if (k == 0) {
         cur = '*';
         opp = 'o';
     }
     else {
         cur = 'o';
         opp = '*';
     }
     bool is_clear = false;
     while (true) {
         int x_ = x + step_down * (step + 1);
         int y_ = y + step_right * (step + 1);
         if (x_ < 0 || x_>7) break;
         if (y_ < 0 || y_>7) break;
         if (board[x_][y_] == opp) {
             step++;
         }
         if (board[x_][y_] == cur) {
             is_clear = true;
             break;
         }
         if (board[x_][y_] == '.') {
             break;
         }
     }
     if (is_clear) {
         for (int i = 0; i <= step; i++) {
             int x_ = x + step_down * i;
             int y_ = y + step_right * i;
             board[x_][y_] = cur;
         }
     }
}

int main() {
    int S;
    cin >> S;
    for (int l = 0; l < S; l++) {
        //datainput
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) { 
                cin >> board[i][j];
            }
        }
        int N;
        cin >> N;
        for (int o = 0; o < N; o++) {
            int x, y, t;
            cin >> x >> y >> t; 
            int clear_step;
            //up
            GetClear(x, y, t, -1, 0);
            //down
            GetClear(x, y, t, 1, 0);
            //left
            GetClear(x, y, t, 0, -1);
            //right
            GetClear(x, y, t, 0, 1);
            //up-left
            GetClear(x, y, t, -1, -1);
            //up-right
            GetClear(x, y, t, -1, 1);
            //down-left
            GetClear(x, y, t, 1, -1);
            //down-right
            GetClear(x, y, t, 1, 1);

            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 8; j++) { 
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        }
        int white_count = 0, black_count = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'o') white_count++;
                if (board[i][j] == '*') black_count++;
            }
        }
        cout << black_count << " " << white_count << endl;
    }
    return 0;
}
