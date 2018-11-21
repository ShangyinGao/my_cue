#include <iostream>

using namespace std;

int fun_static_local (int i_) {
    // compare with global variable?
    static int i = 1;
    i += i_;
    return i;
}

static int i_global = 1; // cannot be used by `extern` in other file

int fun_static_global (int i_) {
    i_global += i_;
    return i_global + i_;
}

// static class variable
class myClass {
    static int sum; // can only be initialized outside class
    int mye;

public:
    myClass(int i_) {
        sum += i_;
    }

    int getSum() {
        return sum;
    }

    void add(int i_) {
        sum += i_;
    }
};

int myClass::sum = 1;

// empty class
class emptyClass {};

class derivedEmptyClass {
    int i;
    emptyClass e_class;
};

// static class method
class myClass2 {
    int i = 0;
    static int i_static;

public:
    myClass2 (int i_) {
        i = i_;
        i_static += i_;
    }

    static int getSum() {
//        return i; // static method can not access non-static variable
        return i_static;
    }
};

int myClass2::i_static = 1;

// explict keyword
class myClass3 {
    double i;

public:
    explicit myClass3(double i_) : i(i_) {}

    double getSum() {
        return i;
    }
};

int main() {
    int a = 10;
    cout << "static local variable" << endl;
    int b = fun_static_local(a);
    cout << a << "\t" << b << endl;
    int c = fun_static_local(a);
    cout << a << "\t" << c << endl;

    cout << "static global variable" << endl;
    int b_global= fun_static_global(a);
    cout << a << "\t" << b_global << endl;
    int c_global = fun_static_global(a);
    cout << a << "\t" << c_global << endl;

    cout << "static class variable" << endl;
    myClass c1(10);
    cout << c1.getSum() << endl;
    cout << "size of c1: " << sizeof(c1) << endl;
    myClass c2(5);
    cout << c1.getSum() << endl;
    cout << "size of c2: " << sizeof(c2) << endl;

    cout << "empty class" << endl;
    emptyClass e;
    cout << "size of empty class: " << sizeof(e) << endl;
    derivedEmptyClass d_e;
    cout << "size of derived empty class: " << sizeof(d_e) << endl; // memory alignment not 5 but 8

    cout << "static class emthod" << endl;
    myClass2 c21(10);
    cout << c21.getSum() << endl;
    cout << myClass2::getSum() << endl; // static can be accessed by className::functionName
    myClass2 c22(5);
    cout << c22.getSum() << endl;
    cout << myClass2::getSum() << endl;


    cout << "class constructor explicit" << endl;
//    myClass3 c31 = 10.;
//    cout << c31.getSum() << endl;explicit

    cout << "copy constructor: shallow copy" << endl;
    myClass c31(10);
    myClass c32(c31);
    c32.add(2);
    cout << c32.getSum() << endl;
    cout << c31.getSum() << endl;
}