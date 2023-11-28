// A program to use std library.

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>
#include <iostream>

using namespace std;

using line_no = vector<string>::size_type;

class QueryResult;

class TextQuery {
public:
    TextQuery(std::ifstream &is);
    QueryResult query(const string &) const;
private:
    shared_ptr<vector<string>> _file;
    map<string, shared_ptr<set<line_no>>> _wm;
};

class QueryResult {
    friend ostream &print (ostream &, const QueryResult &);
public:
    QueryResult (string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f)
        : _sought(s)
        , _lines(p)
        , _file(f) {}
private:
    string _sought;
    shared_ptr<set<line_no>> _lines;
    shared_ptr<vector<string>> _file;
};

void runQueries(ifstream &infiles) {
    TextQuery tq(infiles);
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") {
            break;
        }
        print(cout, tq.query(s)) << endl;
    }
}
