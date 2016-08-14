#include <vector>
using namespace std;
class NumArray {
public:
  NumArray(vector<int> &nums) {
    sum_result.resize(nums.size());
    if (!nums.empty()) {
      sum_result[0] = nums[0];
    }
    for (int i = 1; i < nums.size(); i++) {
      sum_result[i] = sum_result[i - 1] + nums[i];
    }
  }

  int sumRange(int i, int j) {
    if (i == 0) {
      return sum_result[j];
    }
    else {
      return sum_result[j] - sum_result[i - 1];
    }
  }
private:
  vector<int> sum_result;
};
int main() {
  int a[6] = { -2, 0, 3, -5, 2, -1 };
  vector<int> nums(a, a + sizeof(a) / sizeof(int));
  NumArray numArray(nums);
  return 0;
}