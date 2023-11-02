// This is a function to test function copy in library function.

#include<algorithm>
#include<iterator>
#include<string>
#include<iostream>

using namespace std;

void TestCopy() {
    string str1("Hello world!"), str2;
    copy(str1.cbegin(), str1.cend(), back_inserter(str2));
    cout << str2 << endl;
}