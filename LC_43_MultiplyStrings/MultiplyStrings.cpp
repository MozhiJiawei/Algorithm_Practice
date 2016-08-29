/*
Mutiply tow big interger!!!
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        size_t n = num1.length(), m = num2.length();
        vector<int> pos(n + m, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int num = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = num + pos[p2];

                pos[p2] = sum % 10;
                pos[p1] += sum / 10;
            }
        }
        return ToString(pos);
    }
    string ToString(vector<int> pos) {
        string result;
        bool is_zero = true;
        for (int i = 0; i<pos.size(); i++) {
            if (is_zero && pos[i] == 0) {
                continue;
            }
            is_zero = false;
            result.push_back(pos[i] + '0');
        }
        if (is_zero) {
            result = "0";
        }
        return result;
    }
};

int main() {
    cout << "Please input two big interger:" << endl;
    string num1, num2;
    getline(cin, num1);
    getline(cin, num2);
    Solution solu;
    cout << solu.multiply(num1, num2) << endl;
    return 0;
}