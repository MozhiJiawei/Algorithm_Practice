#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

enum PokerType {
    Single, Double, Triple, Bomb, Line
};

unordered_map<string, int> poker_value = { {"3", 0}, {"4", 1}, {"5", 2},
{"6", 3}, {"7", 4}, {"8", 5},{"9", 6}, {"10", 7}, {"J", 8}, {"Q", 9}, {"K", 10},
{"A", 11}, {"2", 12}, {"joker", 13}, {"JOKER", 14} };

struct PokerTypeValue {
    string poker_;
    PokerType type_;
    int value_;
};

void GetPoker(string &input, PokerTypeValue &p1, PokerTypeValue &p2);
void GetType(PokerTypeValue &poker);

int main() {
    string input;
    while (getline(cin, input)) { 
        PokerTypeValue p1, p2;
        GetPoker(input, p1, p2);
        if (p1.type_ != p2.type_) {
            if (p1.type_ == Bomb) {
                cout << p1.poker_ << endl;
            }
            else if (p2.type_ == Bomb) {
                cout << p2.poker_ << endl;
            }
            else {
                cout << "ERROR" << endl;
            }
        }
        else {
            cout << (p1.value_ > p2.value_ ? p1.poker_ : p2.poker_);
        }
    }

}

void GetPoker(string & input, PokerTypeValue & p1, PokerTypeValue & p2) {
    int found = input.find('-');
    p1.poker_ = input.substr(0, found);
    p2.poker_ = input.substr(found + 1);
    GetType(p1);
    GetType(p2);
}

void GetType(PokerTypeValue & input) { 
    vector<string> pokers;
    stringstream ss;
    string poker;
    ss.str(input.poker_);
    while (getline(ss, poker, ' ')) {
        pokers.push_back(poker);
    }
    switch (pokers.size()) {
    case 1:
        input.type_ = Single;
        input.value_ = poker_value[pokers[0]];
        break;
    case 2:
        if (pokers[0] == "joker" || pokers[0] == "JOKER") {
            input.type_ = Bomb;
            input.value_ = poker_value[pokers[0]];
        }
        else {
            input.type_ = Double;
            input.value_ = poker_value[pokers[0]];
        }
        break;
    case 3:
        input.type_ = Triple;
        input.value_ = poker_value[pokers[0]];
        break;
    case 4:
        input.type_ = Bomb;
        input.value_ = poker_value[pokers[0]];
        break;
    case 5:
        input.type_ = Line;
        input.value_ = poker_value[pokers[0]];
        break;
    }
}
