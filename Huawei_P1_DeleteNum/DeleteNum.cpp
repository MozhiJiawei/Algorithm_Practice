#include <list>
#include <iostream>
using namespace std;

int main() {
    int N;
    while (cin >> N) { 
        list<int> num(N);
        int i = 0;
        for (auto itr = num.begin(); itr != num.end(); ++itr, i++) {
            *itr = i;
        }
        auto itr = num.begin();
        while (num.size() != 1) {
            if (++itr == num.end()) {
                itr = num.begin();
            }
            if (++itr == num.end()) {
                itr = num.begin();
            }
            itr = num.erase(itr);
            if (itr == num.end()) {
                itr = num.begin();
            }
        }
        cout << *num.begin() << endl;
    }
    return 0;
}