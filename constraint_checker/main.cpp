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
    unordered_map<char, int> &letter_value);

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
        if (constraints_check(constraints, letter_value)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}

void GetLetter(vector<string> &constraints, 
    unordered_map<char, int> &letter_value) {

    stringstream ss;
    for (int i = 0; i < constraints.size(); i++) {
        string token;
        char letter;
        ss.str(constraints[i]);
        while (getline(ss, token, '<')) {
            letter = (token[0] == '=') ? token[1] : token[0];
            if (letter >= 'A' && letter <= 'Z') {
                letter_value[letter] = 0;
            }
        }
        ss.clear();
    }
}

bool constraints_check(vector<string>& constraints,
    unordered_map<char, int> letter_value) {

    stringstream ss;
    for (int i = 0; i < constraints.size(); i++) {
        int num1, num2;
        string token;
        ss.str(constraints[i]);
        getline(ss, token, '<');
        if (token[0] >= 'A' && token[0] <= 'Z') {
            num1 = letter_value[token[0]];
        }
        else {
            stringstream to_int;
            to_int << token;
            to_int >> num1;
        }
        while (getline(ss, token, '<')) {
            bool is_equal = false;
            if (token[0] == '=') {
                token.erase(token.begin());
                is_equal = true; 
            }
            if (token[0] >= 'A' && token[0] <= 'Z') {
                num2 = letter_value[token[0]];
            }
            else {
                stringstream to_int;
                to_int << token;
                to_int >> num2;
            }
            if (is_equal && num1 > num2) return false;
            if(!is_equal && num1 >= num2) return false;
        }
    }
    return true;
}
