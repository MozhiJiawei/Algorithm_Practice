/*
5
5 5
1 2 3 4 5
4 6
2 3 1 2 2 4
4 6
2 3 1 2 3 4
2 4
1 1 2 2
2 5
1 1 1 2 2
*/
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int S;
    cin >> S;
    for (int l = 0; l < S; l++) {
        int N, L;
        cin >> N >> L;
        unordered_set<int> gift_list;
        vector<int> gifts(L);
        for (int i = 0; i < L; i++) {
            cin >> gifts[i];
        }
        int max_start_index = 0;
        for (int i = 0; i < L; i++) {
            if (gift_list.find(gifts[i]) == gift_list.end()) {
                max_start_index++;
                gift_list.insert(gifts[i]);
            }
            else {
                gift_list.clear();
                break;
            }
        }
        bool is_B;
        for (int i = 0; i <= max_start_index; i++) { 
            is_B = false;
            gift_list.clear();
            for (int j = i; j < L; j++) { 
                if (gift_list.find(gifts[j]) == gift_list.end()) {
                    gift_list.insert(gifts[j]);
                }
                else {
                    is_B = true;
                    break;
                }
                if (gift_list.size() == N) {
                    gift_list.clear();
                }
            }
            if (!is_B) break;
        }
        if (is_B) cout << "B" << endl;
        else cout << "CAN'T DICIDE!" << endl;
    }
    return 0; 
}
