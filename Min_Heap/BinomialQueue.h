#pragma once
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

template <typename Comparable>
class BinomialQueue {
public:
  BinomialQueue();
  BinomialQueue(const Comparable &item);
  BinomialQueue(const BinomialQueue &rhs);
  ~BinomialQueue();

  bool isEmpty() const;
  const Comparable &FindMin() const;

  void Insert(const Comparable &x);
  void DeleteMin();
  void DeleteMin(Comparable & min_item);

  void MakeEmpty();
  void Merge(BinomialQueue &rhs);

  const BinomialQueue & operator=(const BinomialQueue &rhs);
private:
  struct BinomialNode {
    Comparable element_;
    BinomialNode *left_child_;
    BinomialNode *next_sibling_;

    BinomialNode(const Comparable &the_element, BinomialNode *lt,
      BinomialNode *rt) :element_(the_element), left_child_(lt),
      next_sibling_(rt) {};

  };

  int current_size_;
  vector<BinomialNode *> trees_;
 
  int FindMinIndex() const;
  int capacity() const;
  BinomialNode *CombineTrees(BinomialNode *t1, BinomialNode *t2);
  void MakeEmpty(BinomialNode *&t);
  BinomialNode *clone(BinomialNode *t) const;
};

template<typename Comparable>
BinomialNode * BinomialQueue<Comparable>::CombineTrees(BinomialNode * t1, BinomialNode * t2) {
  if (t2->element < t1->element) {
    return CombineTrees(t2, t1);
  }
  else {
    t2->next_sibling_ = t1->left_child_;
    t1->left_child_ = t2; 
    return t1;
  }
}

template<typename Comparable>
void BinomialQueue<Comparable>::Merge(BinomialQueue & rhs) {
  if (this == &rhs) {
    return;
  }

  current_size_ += rhs.current_size_;

  if (current_size_ > capacity()) {
    int old_num_trees = trees_.size();
    int new_num_trees = max(trees_.size(), rhs.trees_.size()) + 1;
    trees_.resize(new_num_trees);
    for (int i = old_num_trees; i < new_num_trees; i++) {
      trees_[i] = NULL;
    }
  }

  BinomialNode *carry = NULL;
  for (int i = 0, j = 1; j <= current_size_; i++, j *= 2) {
    BinomialNode *t1 = trees_[i];
    BinomialNode *t2 = i < rhs.trees_.size() ? rhs.trees_[i] : NULL;

    int which_case = t1 == NULL ? 0 : 1;
    which_case += t2 == NULL ? 0 : 2;
    which_case += carry == NULL ? 0 : 4;

    switch (which_case) {
    case 0:
    case 1:
      break;
    case 2:
      trees_[i] = t2;
      rhs.trees_[i] = NULL;
      break;
    case 4:
      trees_[i] = carry;
      carry = NULL;
      break;
    case 5:
      carry = CombineTrees(t1, carry);
      trees_[i] = NULL;
      break;
    case 6:
      carry = CombineTrees(t2, carry);
      rhs.trees_[i] = NULL;
      break;
    case 7:
      trees_[i] = carry;
    case 3:
      carry = CombineTrees(t1, t2);
      trees_[i] = rhs.trees_[i] = NULL;
      break; 
    } 

    for (int k = 0; k < rhs.trees_.size(); k++) {
      rhs.trees_[k] = NULL;
    }
    rhs.current_size_ = 0;
  }
}
