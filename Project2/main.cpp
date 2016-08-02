/*
3 3
...
...
...
0 1
4
1 0
0 1
-1 0
0 -1
*/
#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct step {
    int dx;
    int dy;
};

vector<vector<bool> > room;
vector<step> steps;
int n, m, min_step = -1;

void Travel(int x, int y, int cur_step, vector<vector<bool> > past_steps) {
    past_steps[x][y] = false;
    if (x == n - 1 && y == m - 1) { 
        if (min_step == -1) {
            min_step = cur_step;
        }
        else if(cur_step < min_step) {
            min_step = cur_step;
        }
        return;
    }
    else if (min_step != -1 && cur_step >= min_step - 1) { 
        return;
    }
    for (int i = 0; i < steps.size(); i++) {
        int nx = x + steps[i].dx, ny = y + steps[i].dy;
        if (nx < n && nx >= 0 &&
            ny < m && ny >= 0) {

            if (room[nx][ny] && past_steps[nx][ny]) {
                Travel(nx, ny, cur_step + 1, past_steps);
            } 
        }
    }
}

int main() {
    vector<vector<bool> > past_steps;
    int x0, y0;
    int k;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<bool> room_line;
        vector<bool> past_step;
        for (int j = 0; j < m; j++) {
            char input;
            cin >> input;
            if (input == '.') {
                room_line.push_back(true);
            }
            if (input == 'X') {
                room_line.push_back(false);
            } 
            past_step.push_back(true);
        }
        past_steps.push_back(past_step);
        room.push_back(room_line);
    }
    cin >> x0 >> y0;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y; 
        step s;
        s.dx = x;
        s.dy = y;
        steps.push_back(s);
    } 
    Travel(x0, y0, 0, past_steps);
    cout << min_step;
    return 0; 
}
