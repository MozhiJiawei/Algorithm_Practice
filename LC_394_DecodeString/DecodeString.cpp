#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string result;
        stack<char> temp;
        for (char c : s) {
            if (c == '[') continue;
            if (c == ']') {
                string temp_string;
                GetString(temp, temp_string);
                int num = GetNum(temp);
                GenerateMultiString(temp_string, num);
                if (temp.empty()) result.append(temp_string);
                else StackPush(temp, temp_string);
                continue;
            }
            if (c < '0' || c > '9') {
                if (temp.empty()) result.push_back(c);
                else temp.push(c);
            }
            if (c >= '0' && c <= '9') {
                temp.push(c);
            }
        }
        return result;
    }
    void GetString(stack<char> &temp, string &s) {
        stack<char> t;
        while (temp.top() < '0' || temp.top() > '9') {
            t.push(temp.top());
            temp.pop();
        }
        while (!t.empty()) {
            s.push_back(t.top());
            t.pop();
        }
    }
    int GetNum(stack<char> &temp) {
        int num = 0;
        while (!temp.empty() && temp.top() >= '0' && temp.top() <= '9') {
            num = num * 10 + (temp.top() - '0');
            temp.pop();
        }
        return num;
    }
    void GenerateMultiString(string &s, int num) {
        string single_s = s;
        while (num > 1) {
            s.append(single_s);
            num--;
        }
    }
    void StackPush(stack<char> &temp, string &s) {
        for (char c : s) {
            temp.push(c);
        }
    }
};

int main() {
    Solution solu;
    string input = "3[a]2[bc]";
    solu.decodeString(input);
    return 0;
}