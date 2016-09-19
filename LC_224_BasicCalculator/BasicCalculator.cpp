#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int character, begin = 0;
        bool is_operator, is_end;
        stack<int> nums;
        stack<char> operators;
        while (true) {
            character = GetNext(s, begin, is_operator, is_end);
            if (is_end) break;
            if (is_operator) {
                if (character == '(' || character == '+' || character == '-') operators.push(character);
                else {
                    operators.pop();
                    while (!operators.empty() && operators.top() != '(') {
                        int n1 = nums.top();
                        nums.pop();
                        int n2 = nums.top();
                        nums.pop();
                        nums.push(operators.top() == '+' ? n2 + n1 : n2 - n1);
                        operators.pop();
                    }
                }
            }
            else {
                if (operators.empty() || operators.top() == '(') {
                    nums.push(character);
                }
                else if (operators.top() == '+') {
                    operators.pop();
                    int n = nums.top();
                    nums.pop();
                    nums.push(n + character);
                }
                else if (operators.top() == '-') {
                    operators.pop();
                    int n = nums.top();
                    nums.pop();
                    nums.push(n - character);
                }
            }
        }
        if (nums.empty()) return 0;
        return nums.top();
    }
    int GetNext(const string &s, int &begin, bool &is_operator, bool &is_end) {
        //skip the space;
        while (begin < s.length() && s[begin] == ' ') begin++;

        // end
        if (begin >= s.length()) {
            is_end = true;
            return 0;
        }
        is_end = false;

        if (s[begin] <= '9' && s[begin] >= '0') {
            // num situation
            is_operator = false;
            int result = 0;
            while (begin < s.length() && s[begin] <= '9' && s[begin] >= '0') {
                result = result * 10 + s[begin] - '0';
                begin++;
            }
            return result;
        }
        else {
            //operator situation
            is_operator = true;
            return s[begin++];
        }
    }
};

int main() {
    Solution solu;
    int result = solu.calculate("(1+(4+5+2)-3)+(6+8)");
    return 0;
}