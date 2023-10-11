// This is a function to show how to use function assign.
// Function Prototype:
// void assign(const_iterator first, const_iterator last);
// void assign(size_type n, const T &x = T());
// It also has some other usage.

#include<iostream>
#include<string>
#include<iterator>

using namespace std;

void TestAssign() {
    const char *ch1 = "Hello world!";
    const char *ch2 = "Test program.";
    string str1(ch1);
    cout << "First string before assign: " << str1 << endl;
    str1.assign(ch2, 6);
    cout << "First string after assign: " << str1 << endl;
    string::const_iterator str1_begin = str1.begin();
    string::const_iterator str1_end = str1.end();
    string str2(ch1);
    cout << "Second string before assign: " << str2 << endl;
    str2.assign(str1_begin + 1, str1_end - 1);
    cout << "Second string after assign: " << str2 << endl;

    string str;
    string other_str = "Other string.";
    // Summary of usage of assign.
    // 1 Direct assignment.
    str.assign(other_str);
    // 2 Assign str from other substr, which has a range.
    str.assign(other_str, 0, 2);
    // 3 Assign str from other substr, which is from pos to end. 
    str.assign(other_str, 0);
    // 4 Assign str using iterator.
    str.assign(other_str.begin(), other_str.end());
    // 5 Assign str from stream.
    str.assign(istream_iterator<char>(cin), istream_iterator<char>());
}
