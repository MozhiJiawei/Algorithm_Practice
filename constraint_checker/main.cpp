/*input:
2
A<B<=E
3<=E<5
2
A 1
B 2
E 3
A 3
B 5
E 10
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>

using namespace std;

void GetLetter(vector<string> &constraints, 
    unordered_map<char, int> letter_value);

bool constraints_check(vector<string> &constraints, 
    unordered_map<char, int> letter_value);

int main() {
    int N, T, K;
    vector<string> constraints;
    unordered_map<char, int> letter_value;
    cin >> N;
    for (int i = 0; i <= N; i++) {
        string constraint;
        getline(cin, constraint);
        if (constraint.length() >= 2) {
            constraints.push_back(constraint);
        }
    }
    GetLetter(constraints, letter_value);
    cin >> T;
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < letter_value.size(); j++) {
            char letter, value;
            cin >> letter >> value;
            letter_value[letter] = value;
        }
        cout << constraints_check(constraints, letter_value);
    }
    return 0;
}

void GetLetter(vector<string> &constraints, 
    unordered_map<char, int> letter_value) {

    //TODO
}

bool constraints_check(vector<string>& constraints, 
    unordered_map<char, int> letter_value) {

    //TODO
    return false;
}
