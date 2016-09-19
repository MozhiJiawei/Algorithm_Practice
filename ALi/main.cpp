#include <iostream>
#include <stdio.h>
using namespace std;

class Test {
public:
    Test(int i = 0) {
        x = i + x;
    }
    int GetNum() {
        return Test::x + 7;
    }
    static int x;
};

int Test::x = 33;

void main() {
    Test test;
    cout << test.GetNum() << endl;
    system("pause");
}
