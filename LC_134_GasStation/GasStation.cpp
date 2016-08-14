#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int min_sum = INFINITY, sum = 0, start;
    for (int i = 0; i < gas.size(); i++) {
      sum += gas[i] - cost[i];
      if (sum < min_sum) {
        min_sum = sum;
        start = i + 1;
      }
    }
    if (sum >= 0) {
      return start;
    }
    else {
      return -1;
    }
  }
};