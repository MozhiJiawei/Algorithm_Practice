/*
abcqweracb
*/
#include <set>
#include <string>
#include <iostream>
using namespace std;

int main() {
    string input;
    set<char> char_set;
    while (getline(cin, input)) {
        for (int i = 0; i < input.length(); i++) {
            if (char_set.count(input[i]) == 0) {
                cout << input[i];
                char_set.insert(input[i]);
            }
        }
        cout << endl;
        char_set.clear();
    }
    return 0;
}