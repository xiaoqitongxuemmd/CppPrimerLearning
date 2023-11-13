#include <iostream>
#include <memory>
#include <string>

using namespace std;

class TestClass {
    int _a;
    string _b;
public:
    TestClass() = default;
    TestClass(int a, string b)
        : _a(a)
        , _b(b) {}
};

void BasicUsageOfSharedPoint() {
    auto pt = make_shared<TestClass>(1, "test");
    auto pt1(pt);
    auto pt2 = pt1;
    cout << "Shared pointer use count is " << pt.use_count() << endl;
    if (pt.unique())
    {
        cout << "Shared pointer is unique." << endl;
    }
    else
    {
        cout << "Shared pointer is not unique." << endl;
    }
}