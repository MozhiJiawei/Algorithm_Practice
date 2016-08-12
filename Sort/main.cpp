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

template <typename Comparable>
void MergeSort(vector<Comparable> &a) {
  vector<Comparable> tmp_array(a.size());
  MergeSort(a, tmp_array, 0, a.size() - 1);
}

template <typename Comparable>
void MergeSort(vector<Comparable> &a, vector<Comparable> &tmp_array, int left, int right) {
  if (left < right) {
    int center = (left + right) / 2;
    MergeSort(a, tmp_array, left, center);
    MergeSort(a, tmp_array, center + 1, right);
    Merge(a, tmp_array, left, center + 1, right);
  }
}

template <typename Comparable>
void Merge(vector<Comparable> &a, vector<Comparable> &tmp_array, int left_pos,
    int right_pos, int right_end) {
  
  int left_end = right_pos - 1;
  int tmp_pos = left_pos;
  int num_elements = right_end - left_pos + 1;

  while (left_pos <= left_end && right_pos <= right_end) {
    if (a[left_pos] <= a[right_pos]) {
      tmp_array[tmp_pos++] = a[left_pos++];
    }
    else {
      tmp_array[tmp_pos++] = a[right_pos++];
    }
  }

  while (left_pos <= left_end) {
    tmp_array[tmp_pos++] = a[left_pos++];
  }

  while (right_pos <= right_end) {
    tmp_array[tmp_pos++] = a[right_pos++];
  }
  for (int i = 0; i < num_elements; i++, right_end--) {
    a[right_end] = tmp_array[right_end]
  }
}

template <typename Comparable>
void QuickSort(vector<Comparable> &a) {
  QuickSort(a, 0, a.size() - 1);
}

template <typename Comparable>
const Comparable & median3(vector<Comparable> &a, int left, int right) {
  int center = (left + right) / 2;
  if (a[center] < a[left]) {
    swap(a[left], a[center]);
  }
  if (a[right] < a[left]) {
    swap(a[left], a[right]);
  }
  if (a[right] < a[center]) {
    swap(a[center], a[right]);
  }
  swap(a[center], a[right - 1]);
  return a[right - 1];
}

template <typename Comparable>
void QuickSort(vector<Comparable> &a, int left, int right) {
  if (left + 10 <= right) {
    Comparable pivot = median3(a, left, right);
    int i = left, j = right - 1;
    while (true) {
      while (a[++i] < pivot);
      while (pivot < a[--j]);
      if (i < j) {
        swap(a[i], a[j]);
      }
      else {
        break;
      }
    }
    swap(a[i], a[right - 1]);
    QuickSort(a, left, i - 1);
    QuickSort(a, i + 1, right);
  }
  else {
    InsertSort(a, left, right);
  }
}

template <typename Comparable>
Comparable &QuickSelect(vector<Comparable> &a, int left, int right, int k) { 
  if (left + 10 <= right) {
    Comparable pivot = median3(a, left, right);
    int i = left, j = right - 1;
    while (true) {
      while (a[++i] < pivot);
      while (pivot < a[--j]);
      if (i < j) {
        swap(a[i], a[j]);
      }
      else {
        break;
      }
    }
    swap(a[i], a[right - 1]);
    if (k == i + 1) {
      return a[i];
    }
    else if (k < i + 1) {
      return QuickSelect(a, left, i - 1, k);
    }
    else {
      return QuickSelect(a, i + 1, right, k - i - 1);
    }
  }
  else {
    InsertSelect(a, left, right, k);
  }
}

template <typename Comparable>
class Pointer {
public:
  Pointer(Comparable *rhs = NULL) :pointee(rhs) {}

  bool operator<(const Pointer &rhs) const {
    return *pointee < *rhs.pointee;
  }
  operator Comparable*() const {
    return pointee;
  }
private:
  Comparable *poitee;
};

template <typename Comparable>
void LargeObjectSort(vector<Comparable> &a) {
  vector<Pointer<Comparable> > p(a.size());
  int i, j, nextj;
  for (i = 0; i < a.size(); i++) { 
    p[i] = &a[i];
  }
  QuickSort(p);
  for (i = 0; i < a.size(); i++) {
    if (p[i] != &a[i]) {
      Comparable tmp = a[i];
      for (j = i; p[j] != &a[i]; j = nextj) {
        nextj = p[j] - &a[0];
        a[j] = *p[j];
        p[j] = &a[j];
      }
      a[j] = tmp;
      p[j] = &a[j];
    }
  }
}

int main() {
    return 0;
}
