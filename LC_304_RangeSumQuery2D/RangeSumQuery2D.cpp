#include <vector>
using namespace std;

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        for (int i = 0; i<matrix.size(); i++) {
            vector<int> line_i;
            int sum_i = 0;
            for (int j = 0; j<matrix[i].size(); j++) {
                sum_i += matrix[i][j];
                if (i == 0) {
                    line_i.push_back(sum_i);
                }
                else {
                    line_i.push_back(sum_i + sum_result_[i - 1][j]);
                }
            }
            sum_result_.push_back(line_i);
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return sum_result_[row2][col2];
        }
        else if (row1 == 0) { 
            return sum_result_[row2][col2] - sum_result_[row2][col1 - 1];
        }
        else if (col1 == 0) {
            return sum_result_[row2][col2] - sum_result_[row1 - 1][col2];
        }
        else {
            return (sum_result_[row2][col2] - sum_result_[row1 - 1][col2]) -
                (sum_result_[row2][col1 - 1] - sum_result_[row1 - 1][col1 - 1]);
        }
    }
private:
    vector<vector<int> > sum_result_;
};

int main() {
    vector<vector<int> > matrix(5, vector<int>(5, 1));
    NumMatrix numMatrix(matrix);
    int n = numMatrix.sumRegion(1, 1, 2, 2);
}