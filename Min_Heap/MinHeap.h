#pragma once
#include <vector>
using namespace std;

template <typename Comparable>
class BinaryHeap {
public:
    explicit BinaryHeap(int capacity = 100);
    explicit BinaryHeap(const vector<Comparable> & item);

    bool IsEmpty() const;
    const Comparable & FindMin() const;

    void Insert(const Comparable &x);
    void DeleteMin();
    void DeleteMin(Comparable &min_item);
    void MakeEmpty();

private:
    int current_size_;
    vector<Comparable> array_;
    
    void BuildHeap();
    void PercolateDown(int hole);
};

