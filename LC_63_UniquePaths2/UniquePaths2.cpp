#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;
        int n = int(obstacleGrid.size()), m = int(obstacleGrid[0].size());
        unordered_map<int, int> cur_path;
        cur_path[0] = 1;
        for (int step = 0; step<m + n - 2; step++) {
            unordered_map<int, int> next_path;
            for (auto x : cur_path) {
                int col = x.first;
                int row = step - col;
                if (row < n - 1 && obstacleGrid[row + 1][col] != 1) {
                    if (next_path.count(col) == 0) next_path[col] = x.second;
                    else next_path[col] += x.second;
                }
                if (col < m - 1 && obstacleGrid[row][col + 1] != 1) {
                    if (next_path.count(col + 1) == 0) next_path[col + 1] = x.second;
                    else next_path[col + 1] += x.second;
                }
            }
            if (next_path.empty()) return 0;
            cur_path = next_path;
        }
        return cur_path.begin()->second;
    }
};

int main() {
    vector<vector<int>> a(1, vector<int>(2, 0));
    Solution solu;
    cout << solu.uniquePathsWithObstacles(a) << endl;
    return 0;
}