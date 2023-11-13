// This is a function to test function bind in library functional.

#include<iostream>
#include<functional>

using namespace std;

int Plus(int l, int r) {
    return l + r;
}

int SelectFirst(int first, int second) {
    return first;
}

void TestBind() {
    int x = 1;
    auto func1 = bind(Plus, placeholders::_1, x);
    // Placeholder is used to show which parameter
    cout << "Plus function result:" << func1(2) << endl;
    auto func2 = bind(SelectFirst, x, placeholders::_1);
    cout << "SelectFirst and placeholder second result:" << func2(2) << endl;
    auto func3 = bind(SelectFirst, placeholders::_1, x);
    cout << "SelectFirst and placeholder first result:" << func3(2) << endl;
}

// placeholder is assignment location in the function that calling.