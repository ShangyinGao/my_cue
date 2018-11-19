#include <iostream>

using namespace std;

// Base-Class: function override
// Sub-Class: same function name as in Base-Class
// ?: can we use override function from Base-Class

class Base {
public:
    virtual void fun() {
        cout << "Base: fun()" << endl;
    }
    virtual void fun(int i) {
        cout << "Base: fun(int)" << endl;
    }
    virtual void fun(double i) {
        cout << "Base: fun(double)" << endl;
    }
};

class Derived : public Base {
public:
    virtual void fun(int i) override {
        cout << "Derived: fun()" << endl;
    }
};

class Base2 {
public:
    void fun() {
        cout << "Base2 fun()" << endl;
    }
};

class Base3 {
public:
    void fun() {
        cout << "Base3 fun()" << endl;
    }
};

class Derived2 : public Base2, public Base3 {
public:
    void fun() {
        Base2::fun();
    }
};

class Derived22 : public virtual Base2 {};

class Derived23 : public virtual Base2 {};

class Derived24 : public Derived22, public Derived23 {};

int main () {
    // function override
    Base b;
    b.fun();
    b.fun(2);
    b.fun(2.);
    Derived d;
//    d.fun();
    d.fun(1);
    d.fun(1.);

    // 同名二义性
    Derived2 d2;
    d2.fun();
    d2.Base3::fun();

    // 路径二义性
    Derived24 d3;
    d3.fun();
}