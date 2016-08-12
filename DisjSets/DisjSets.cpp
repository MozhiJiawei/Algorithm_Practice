#include <vector>
using namespace std;

class DisjSets {
public:
  explicit DisjSets(int num_elements);

  int find(int x) const;
  int find(int x);
  void unionSets(int root1, int root2);

private:
  vector<int> s;
};

DisjSets::DisjSets(int num_elements) :s(num_elements) {
  for (int i = 0; i < s.size(); i++) {
    s[i] = -1;
  }
}

void DisjSets::unionSets(int root1, int root2) {
  // method1
  s[root2] = root1;
  // method2: union according to height
  if (s[root2] < s[root1]) {
    s[root1] = root2;
  }
  else {
    if (s[root1] == s[root2]) {
      s[root1]--;
    }
    s[root2] = root1;
  }
}

int DisjSets::find(int x) const {
  if (s[x] < 0) {
    return x;
  }
  else {
    return find(s[x]);
  }
}

int DisjSets::find(int x) {
  if (s[x] < 0) {
    return x;
  }
  else {
    return s[x] = find(s[x]);
  }
}

int main() {
  return 0;
}