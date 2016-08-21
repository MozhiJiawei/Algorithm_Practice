#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

struct error_data {
    string error_name_;
    int line_;
    int num_;
};

void GetFileLine(string &input, string &file, int & line);
int ErrorExists(vector<error_data> &errors, error_data error);
int GetFirstError(vector<error_data> &errros);

int main() {
    int count = 0;
    string input;
    vector<error_data> errors;
    while (getline(cin, input)) {
        error_data error;
        GetFileLine(input, error.error_name_, error.line_);
        int found = ErrorExists(errors, error);
        if (found != -1) {
            errors[found].num_++;
        }
        else{
            error.num_ = 1;
            errors.push_back(error);
        }
    }
    for (int i = 0; i < 8 && i < errors.size(); i++) {
        int found = GetFirstError(errors);
        if (found != -1) {
            if (errors[found].error_name_.length() > 16) {
                cout << errors[found].error_name_.substr(errors[found].error_name_.length() - 16);
            }
            else {
                cout << errors[found].error_name_;
            }
            cout << " " << errors[found].line_ << " " << errors[found].num_ << endl; 
            errors[found].num_ = 0;
        }
        else {
            break;
        }
    }
    return 0;
}

void GetFileLine(string & input, string & file, int & line) {
    stringstream ss;
    ss.str(input);
    string filename, line_string;
    getline(ss, filename, ' ');
    getline(ss, line_string, ' ');
    size_t found = filename.rfind('\\');
    file = filename.substr(found + 1);
    ss.clear();
    ss.str(line_string);
    ss >> line;
}

int ErrorExists(vector<error_data>& errors, error_data error) {
    for (int i = 0; i < errors.size(); i++) {
        if (errors[i].error_name_ == error.error_name_ && 
            errors[i].line_ == error.line_) {

            return i;
        }
    }
    return -1;
}

int GetFirstError(vector<error_data> &errors) {
    int found = -1;
    for (int i = 0; i < errors.size(); i++) {
        if (found == -1 && errors[i].num_ != 0) {
            found = i;
        }
        if (found != -1 && errors[i].num_ > errors[found].num_) {
            found = i;
        }
    }
    return found;
}
