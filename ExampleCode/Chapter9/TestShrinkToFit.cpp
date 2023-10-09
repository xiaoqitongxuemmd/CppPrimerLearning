// This is a function to test shrink_to_fit how to effect capacity.

#include<iostream>
#include<vector>

using namespace std;

void TestShrinkToFit() {
    vector<int> v;
    for (vector<int>::size_type i = 0; i < 17; ++i) {
        v.push_back(i);
    }
    cout << "Capacity before shrink_to_fit: " << v.capacity() << endl;
    v.shrink_to_fit();
    cout << "Capacity after shrink_to_fit: " << v.capacity() << endl;
}
