#include "MinHeap.h"

template<typename Comparable>
void BinaryHeap<Comparable>::Insert(const Comparable & x) {
    if (current_size_ == array_.size() - 1) {
        array_.resize(array_.size() * 2);
    }
    int hole = ++current_size_;
    for (; hole > 1 && x < array_[hole / 2]; hole /= 2) {
        array_[hole] = array_[hole / 2];
    }
    array_[hole] = x;
}

template<typename Comparable>
void BinaryHeap<Comparable>::DeleteMin() {
    array_[1] = array_[current_size_--];
    PercolateDown(1);
}

template<typename Comparable>
void BinaryHeap<Comparable>::DeleteMin(Comparable & min_item) {
    min_item = array_[1];
    array_[1] = array_[current_size_--];
    PercolateDown(1);
}

template<typename Comparable>
void BinaryHeap<Comparable>::PercolateDown(int hole) {
    Comparable tmp = array_[hole];
    int child;
    for (; hole * 2 <= current_size_; hole = child) {
        child = hole * 2;
        if (child != current_size_ && array_[child] > array_[child + 1]) { 
            child++;
        }
        if (tmp <= array_[child]) {
            break;
        }
        else {
            array_[hole] = array_[child];
        }
    }
    array_[hole] = tmp;
}
