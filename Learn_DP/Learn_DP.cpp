#include <vector>
#include <iostream>
using namespace std;

int fibonacci(int n) {
  if (n <= 1)
    return 1;
  int last = 1;
  int next_to_last = 1;
  int answer = 1;
  for (int i = 2; i <= n; i++) {
    answer = last + next_to_last;
    next_to_last = last;
    last = answer;
  }
  return answer;
}

double eval(int n) {
  vector<double> c(n + 1);

  c[0] = 1.0;
  double sum = 1.0;
  for (int i = 1; i <= n; i++) {
    c[i] = 2.0*sum / i + i;
    sum += c[i];
  }

  return c[n];
}

void optMatrix(const vector<int> &c, vector<vector<long> > &m,
    vector<vector<int> > & lastChange) {
  
  int n = c.size() - 1;

  for (int left = 1; left <= n; left++) {
    m[left][left] = 0;
  }
  for (int k = 1; k < n; k++) {
    for (int left = 1; left <= n - k; left++) {
      int right = left + k;
      m[left][right] = INFINITY;
      for (int i = left; i < right; i++) {
        long this_cost = m[left][i] + m[i + 1][right] + c[left - 1] * c[i] * c[right];
        if (this_cost < m[left][right]) {
          m[left][right] = this_cost;
          lastChange[left][right] = i;
        }
      }
    }
  }
}

int main() {
  cout << eval(3);
  system("pause");
  return 0;
}