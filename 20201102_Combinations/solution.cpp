#include "solution.hpp"

vector<vector<int>> combine_iter(int n, int k)
{
    vector<vector<int>> collection;
    vector<int> current_combine;
    int v = 1;

    auto backtrace = [&v, &current_combine]() {
        v = current_combine.back();
        current_combine.pop_back();
    };

    while (true) {
        if (current_combine.size() == k) {
            // find one combination
            collection.push_back(vector<int>{current_combine});  // copy
            backtrace();
        } else if (k - current_combine.size() + v - 1 > n) {
            // done all combinations
            if (current_combine.empty()) return collection;
            backtrace();
        } else {
            current_combine.push_back(v);
        }
        ++v;
    }
}

vector<vector<int>> Solution::combine(int n, int k)
{
    return combine_iter(n, k);
}