#include "solution.hpp"

char Solution::nextGreatestLetter(vector<char>& letters, char target)
{
    int lo = 0;
    int hi = letters.size() - 1;

    auto wrap_index = [&](int i) {
        do {
            ++i;
            if (i >= letters.size()) {
                i = 0;
                // at least two unique letter,
                // so letters.first != letters.last
                break;
            }
        } while (letters[i] == letters[i - 1]);
        return letters[i];
    };

    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;

        if (letters[mi] == target) {
            return wrap_index(mi);
        }

        if (letters[mi] > target) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    return letters[lo] > target ? letters[lo] : wrap_index(lo);
}