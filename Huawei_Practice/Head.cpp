#include "Head.h"

#include <sstream>
using namespace std;

void Stringchang(const char * input, char * output) {
    string s_input(input);
    for (int i = 0; i < s_input.size(); i++) {
        if (input[i] < 'z' && input[i] >= 'a' ||
            input[i] < 'Z' && input[i] >= 'A') {

            output[i] = input[i] + 1;
        }
        else if (input[i] == 'z') {
            output[i] = 'a';
        }
        else if (input[i] == 'Z') {
            output[i] = 'A';
        }
        else {
            output[i] = input[i];
        }
    }
}

int same(int num) {
    stringstream ss;
    string snum;
    ss << num;
    snum = ss.str();
    for (int i = 0; i < snum.length() - 3; i++) {
        for (int j = i + 2; j < snum.length(); j++) {
            if (snum[j] == snum[i] && snum[j + 1] == snum[i + 1]) {
                return 1;
            }
        }
    }
    return 0;
}

void mul(char * input1, int n, char * input2, int m, char * output) {
    stringstream ss;
    int num1, num2, result;
    ss.str(input1);
    ss >> num1;

    ss.clear();
    ss.str(input2);
    ss >> num2;

    ss.clear();
    ss.str("");
    result = num1 * num2;
    ss << result;
    strcpy(output, ss.str().c_str());
}

int DeleteSubstring(string & str, const string & sub) {
    size_t found, count = 0;
    found = str.find(sub);
    while (found != string::npos) { 
        count++;
        str.erase(found, sub.length());
        found = str.find(sub, found);
    }
    return count;
}
