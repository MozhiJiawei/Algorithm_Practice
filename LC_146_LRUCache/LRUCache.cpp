// Combination of hash_map and double_linkded_list
#include <unordered_map>
#include <iostream>
using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        head = new DListNode(0, 0);
        tail = new DListNode(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (Cache_.count(key) > 0) {
            DListNode *p = Cache_[key];
            MoveTop(p);
            return p->value;
        }
        else {
            return -1;
        }
    }

    void set(int key, int value) {
        if (Cache_.count(key) > 0) {
            DListNode *p = Cache_[key];
            p->value = value;
            MoveTop(p);
            return;
        }
        DListNode *p = new DListNode(key, value);
        Insert(p);
        if (Cache_.size() > capacity_) DeleteLast();
    }
private:
    struct DListNode {
        int key;
        int value;
        DListNode *next;
        DListNode *prev;
        DListNode(int k, int v) : key(k), value(v), next(NULL), prev(NULL) {}
    };
    unordered_map<int, DListNode*> Cache_;
    int capacity_;
    DListNode *head, *tail;

    void MoveTop(DListNode *&p) {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = head->next;
        p->prev = head;
        head->next->prev = p;
        head->next = p;
    }

    void Insert(DListNode *p) {
        Cache_[p->key] = p;
        p->next = head->next;
        p->prev = head;
        head->next->prev = p;
        head->next = p;
    }

    void DeleteLast() {
        DListNode *last = tail->prev;
        last->prev->next = tail;
        tail->prev = last->prev;
        Cache_.erase(last->key);
        delete last;
    }
};

int main() {
    LRUCache a(1);
    a.set(2, 1);
    cout << a.get(1) << a.get(2) << endl;
    return 0;
}