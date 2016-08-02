#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void GetOutput(vector<int> &num, bool &end_flag);

int main() { 
    vector<int> num;
    int n;
    bool end_flag = true;
    cin >> n;
    for (int i = 0; i < 4; i++) {
        num.push_back(n % 10);
        n = n / 10; 
    }
    while (end_flag) { 
        GetOutput(num, end_flag);
    }
    return 0;
}

void GetOutput(vector<int>& num, bool &end_flag) {
    int n_new;
    sort(num.begin(), num.end());
    for (int i = 0; i < 4; i++) {
        cout << num[3 - i];
    }
    cout << " - ";
    for (int i = 0; i < 4; i++) {
        cout << num[i];
    }
    cout << " = "; 
    n_new = num[3] * 1000 + num[2] * 100 + num[1] * 10 + num[0] -
        num[0] * 1000 - num[1] * 100 - num[2] * 10 - num[3];
    
    num.clear();
    for (int i = 0, n = n_new; i < 4; i++) {
        num.push_back(n % 10);
        n = n / 10; 
    }
    for (int i = 0; i < 4; i++) {
        cout << num[3 - i];
    }
    if (n_new == 0 || n_new == 6174) {
        cout << flush;
        end_flag = false;
    }
    else {
        cout << endl << endl;
    }
}
