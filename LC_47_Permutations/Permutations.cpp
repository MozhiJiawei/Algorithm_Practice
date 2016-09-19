#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        permute(nums, 0, result);
        return result;
    }
    void permute(vector<int> &num, int begin, vector<vector<int>> &result) {
        if (begin > num.size()) {
            result.push_back(num);
            return;
        }
        unordered_set<int> used_num;
        for (int i = begin; i<num.size(); i++) {
            if (used_num.count(num[i]) == 0) {
                swap(num[i], num[begin]);
                permute(num, begin + 1, result);
                swap(num[i], num[begin]);
                used_num.insert(num[i]);
            }
        }
    }
};

int main() {
    Solution solu;
    vector<int> nums{ 1,1,2,2 };
    solu.permuteUnique(nums);
    return 0;
}