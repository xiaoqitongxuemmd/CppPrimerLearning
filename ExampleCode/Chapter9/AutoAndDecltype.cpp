// This is a function to show difference between auto and decltype.

#include<iostream>

using namespace std;

void AutoAndDecltype() {
    int a = 0;
    const int &cra = a;
    auto cra1 = cra;
    cra1 = 1; // cra1 can change, which means it is not const.
    cout << "auto a = " << a << endl; // a will equal to 0, which means it is not a reference.
    decltype(cra) cra2 = cra;
    // cra2 = 1; This line will build fail, which means it is a const.
    int &cra_ = a;
    decltype(cra_) cra3 = cra_;
    cra3 = 1;
    cout << "decltype a = " << a << endl; // a will equal to 1, means it is a reference.
}

// The whole program shows that auto will ignore const and reference, but decltype will not do so.