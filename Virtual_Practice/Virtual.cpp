#include <iostream>
#include <vector>
using namespace std;

class X {
public :
    virtual void f() { cout << "X "; }
};

class A :X {
public:
    virtual void f() { cout << "A "; }
};

class B :X {
public:
    void f() { cout << "B "; }
};

class D :A {
public:
    virtual void f() { cout << "D "; }
};

class E :B {
public:
    virtual void f() { cout << "E "; }
};

int main() {
    vector<void*> tmp;
    tmp.push_back(new X());
    tmp.push_back(new A());
    tmp.push_back(new D());
    tmp.push_back(new B());
    tmp.push_back(new E());
    for (int i = 0; i < tmp.size(); i++) { 
        B* b = static_cast<B*>(tmp[i]);
        b->f();
    }
    return 0;
}