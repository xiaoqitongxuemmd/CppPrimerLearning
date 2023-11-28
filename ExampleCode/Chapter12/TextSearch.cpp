#include "TextSearch.h"
#include <sstream>

TextQuery::TextQuery(std::ifstream &is) {
    string text;
    while (getline(is, text)) {
        _file->push_back(text);
        int n = _file->size() - 1;
        istringstream line(text); // istringstream will split line into word.
        string word;
        while (line >> word) {
            auto &lines = _wm[word];
            if (!lines) {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = _wm.find(sought);
    if (loc == _wm.end()) {
        return QueryResult(sought, nodata, _file);
    }
    else {
        return QueryResult(sought, loc->second, _file);
    }
}

ostream &print(ostream &os, const QueryResult &qr) {
    auto make_plural = [](size_t size, const string &words, const string &end) -> string {
        return size > 1 ? words : words + end;
    };
    os << qr._sought << " occurs " << qr._lines->size() << " " << make_plural(qr._lines->size(), "time", "s");
    for (auto num : *qr._lines) {
        os << "\t(line " << num + 1 << ") " << *(qr._file->begin() + num) << endl;
    }
    return os;
}
