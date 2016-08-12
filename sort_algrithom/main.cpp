#include <vector>
using namespace std;
template <typename Comparable>
void InsertionSort(vector<Comparable> &a) { 
  int j;

  for (int p = 1; p < a.size(); p++) {
    Comparable tmp = a[p];
    for (j = p; j > 0 && tmp < a[j - 1]; j--) { 
      a[j] = a[j - 1];
    }
    a[j] = tmp;
  }
}

template <typename Comparable>
void ShellSort(vector<Comparable> &a) {
  int j;
  for (int gap = a.size() / 2; gap >= 1; gap /= 2) {
    for (int i = gap; i < a.size(); i++) { 
      Comparable tmp = a[i];
      j = i;
      while (j >= gap &&tmp < a[j - gap]) {
        a[j] = a[j - gap];
        j- = gap;
      }
      a[j] = tmp;
    } 
  }
}

int main() {
  return 0;
}