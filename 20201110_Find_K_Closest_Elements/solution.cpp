#include "solution.hpp"

#include <algorithm>
#include <cmath>
#include <deque>

int binary_search(vector<int>& arr, int x)
{
    int lo = 0;
    int hi = arr.size() - 1;

    while (lo <= hi) {
        int mi = lo + (hi - lo) / 2;

        if (arr[mi] == x) {
            return mi;
        }

        if (arr[mi] > x) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    return hi;
}

int min_index(vector<int>& arr, int x, int i, int j)
{
    return abs(arr[i] - x) <= abs(arr[j] - x) ? i : j;
}

vector<int> Solution::findClosestElements(vector<int>& arr, int k, int x)
{
    int i = binary_search(arr, x);
    int j = i + 1;

    deque<int> result{};
    for (; k > 0; --k) {
        if (i < 0) {
            result.push_back(arr[j++]);
            continue;
        }
        if (j >= arr.size()) {
            result.push_front(arr[i--]);
            continue;
        }

        int mini = min_index(arr, x, i, j);
        if (mini == i) {
            result.push_front(arr[i--]);
        } else {
            result.push_back(arr[j++]);
        }
    }

    return vector<int>{result.begin(), result.end()};
}