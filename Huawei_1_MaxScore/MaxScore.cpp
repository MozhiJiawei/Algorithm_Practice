/*
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5
5 7
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
Q 4 5
U 4 5
U 2 9
Q 1 5
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    while (cin >> N >> M) {
        vector<int> score(N);
        for (int i = 0; i < N; i++) {
            cin >> score[i];
        }
        for (int i = 0; i < M; i++) {
            char operation;
            int A, B;
            cin >> operation >> A >> B;
            switch (operation) {
            case 'Q':
                if (A > B) swap(A, B);
                cout << *max_element(score.begin() + A - 1, score.begin() + B) << endl;
                break;
            case 'U':
                score[A - 1] = B;
                break;
            default:
                break;
            }
        }
    }
    return 0;
}