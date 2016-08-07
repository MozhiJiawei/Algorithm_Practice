/*
3 3
X.X
.X.
...
0 1
4
1 0
0 1
-1 0
0 -1
*/
/*
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
int n, m, min_step = -1, tar_x, tar_y;

void Travel(int x, int y, int cur_step, vector<vector<bool> > past_steps) {
    past_steps[x][y] = false;
    if (x == tar_x && y == tar_y) { 
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
    int result = -1;
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
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) {
            if (i == x0 && j == y0) {
                continue;
            }
            if (room[i][j] == true) {
                tar_x = i;
                tar_y = j;
                min_step = -1;
                Travel(x0, y0, 0, past_steps); 
                if (result == -1) {
                    result = min_step;
                }
                else if (min_step > result) {
                    result = min_step;
                }
            }
        }
    }
    cout << result << flush;
    return 0; 
}
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;
struct step {
    step(int xx, int yy):x(xx), y(yy) {}
    int x;
    int y;
};

int main() {
    vector<vector<int> > room;
    int x0, y0, m, n, k;
    vector<step> steps;
    int max_step = -1;
    vector<step> cur_point;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<int> room_line;
        for (int j = 0; j < m; j++) {
            char input;
            cin >> input;
            if (input == '.') {
                room_line.push_back(-1);
            }
            if (input == 'X') {
                room_line.push_back(-2);
            }
        }
        room.push_back(room_line);
    }
    cin >> x0 >> y0; 
    cin >> k;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        steps.push_back(step(x, y));
    }
    cur_point.push_back(step(x0, y0));
    room[x0][y0] = 0;
    while (true) {
        bool no_other_root = true;
        vector<step> new_cur_point;
        for (size_t i = 0; i < cur_point.size(); i++) {
            for (size_t j = 0; j < steps.size(); j++) { 
                int nx, ny;
                nx = cur_point[i].x + steps[j].x;
                ny = cur_point[i].y + steps[j].y;
                if (nx < n && nx >= 0 &&
                    ny < m && ny >= 0) { 

                    if (room[nx][ny] == -1) { 
                        if (max_step == -1) room[nx][ny] = 1;
                        else room[nx][ny] = max_step + 1;
                        no_other_root = false;
                        new_cur_point.push_back(step(nx, ny));
                    }
                }
            }
        }
        cur_point = new_cur_point;
        if (no_other_root) {
            break;
        }
        else {
            if (max_step == -1) {
                max_step = 1;
            }
            else {
                max_step++;
            }
        }
    }
    cout << max_step << flush;
    return 0;
}