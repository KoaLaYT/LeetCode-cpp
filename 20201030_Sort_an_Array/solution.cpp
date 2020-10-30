#include "solution.hpp"

#include <algorithm>
#include <iterator>

using It = vector<int>::iterator;

void merge(vector<int>& nums, It lo, It mi, It hi)
{
    vector<int> aux(std::distance(lo, hi));
    It i = lo;
    It j = mi;

    for (It k = aux.begin(); k != aux.end(); ++k) {
        if (i == mi) {
            *k = *j;
            ++j;
        } else if (j == hi) {
            *k = *i;
            ++i;
        } else if (*i <= *j) {
            *k = *i;
            ++i;
        } else {
            *k = *j;
            ++j;
        }
    }

    std::copy(aux.begin(), aux.end(), lo);
}

void merge_sort(vector<int>& nums, It lo, It hi)
{
    auto dist = std::distance(lo, hi);
    if (dist <= 1) return;
    // 1. divide
    It mi = lo;
    std::advance(mi, dist / 2);
    merge_sort(nums, lo, mi);
    merge_sort(nums, mi, hi);
    // 2. conquer
    merge(nums, lo, mi, hi);
}

vector<int> Solution::sortArray(vector<int>& nums)
{
    vector<int> copy{nums};
    merge_sort(copy, copy.begin(), copy.end());
    return copy;
}