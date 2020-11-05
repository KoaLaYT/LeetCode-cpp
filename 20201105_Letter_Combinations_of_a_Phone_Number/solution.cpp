#include "solution.hpp"

#include <optional>
#include <unordered_map>

unordered_map<char, vector<char>> LETTER_MAP{
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}},
};

class LetterCombination {
public:
    LetterCombination(string& digits) : d{&digits}, pos(digits.length()) {}
    vector<string> generate();

private:
    string* d;
    string s;
    vector<int> pos;

    int size() { return d->length(); }
    bool found() { return s.length() == size(); }
    void backtrace() { s.pop_back(); }
    int& current_pos() { return pos[s.length()]; }
    vector<char>& current_chars() { return LETTER_MAP[(*d)[s.length()]]; }
    bool is_at_limit(int pos) { return pos >= current_chars().size(); }

    optional<char> next();
};

optional<char> LetterCombination::next()
{
    int p = current_pos();
    if (is_at_limit(p)) {
        if (s.empty()) return nullopt;
        current_pos() = 0;
        backtrace();
        return next();
    }
    char c = current_chars()[p];
    ++current_pos();
    return optional{c};
}

vector<string> LetterCombination::generate()
{
    vector<string> letters;

    while (true) {
        if (found()) {
            letters.push_back(string{s});
            backtrace();
        } else {
            optional<char> c = next();
            if (!c.has_value()) break;
            s += c.value();
        }
    }

    return letters;
}

vector<string> Solution::letterCombinations(string digits)
{
    if (digits.empty()) return vector<string>{};

    LetterCombination lc{digits};
    return lc.generate();
}