#include "solution.hpp"

#include <algorithm>
#include <cmath>

using Index = int;  // vector<int>::size_type;

class SegmentTree {
public:
    explicit SegmentTree(vector<int>& arr) : a{&arr}
    {
        auto size = a->size();
        double height = ceil(log2(double(size)));
        t.resize(2 * pow(2.0, height) - 1);
        builder(0, size - 1, 0);
    }

    Index min_range(Index qs, Index qe)
    {
        return min_range_recu(qs, qe, 0, a->size() - 1, 0);
    }

    int& at(Index i) const { return (*a)[i]; }

private:
    vector<Index> t;
    vector<int>* a;

    Index mid(Index lo, Index hi) { return lo + (hi - lo) / 2; }
    Index min_val(Index left, Index right)
    {
        if (left == -1) return right;
        if (right == -1) return left;
        return at(left) <= at(right) ? left : right;
    }
    Index builder(Index lo, Index hi, Index i);
    Index min_range_recu(Index qs, Index qe, Index lo, Index hi, Index i);
};

Index SegmentTree::builder(Index lo, Index hi, Index i)
{
    if (lo == hi) {
        t[i] = lo;
    } else {
        Index mi = mid(lo, hi);
        t[i] = min_val(builder(lo, mi, 2 * i + 1), builder(mi + 1, hi, 2 * i + 2));
    }
    return t[i];
}

Index SegmentTree::min_range_recu(Index qs, Index qe, Index lo, Index hi, Index i)
{
    if (qs <= lo && qe >= hi) return t[i];

    if (qe < lo || qs > hi) return -1;

    Index mi = mid(lo, hi);
    return min_val(min_range_recu(qs, qe, lo, mi, 2 * i + 1),
                   min_range_recu(qs, qe, mi + 1, hi, 2 * i + 2));
}

int largest(SegmentTree& st, Index lo, Index hi)
{
    if (lo > hi) return 0;
    if (lo == hi) return st.at(lo);

    Index mi = st.min_range(lo, hi);

    return max({largest(st, lo, mi - 1),         // left
                largest(st, mi + 1, hi),         // right
                int(hi - lo + 1) * st.at(mi)});  // combined
}

int Solution::largestRectangleArea(vector<int>& heights)
{
    if (heights.empty()) return 0;

    SegmentTree st{heights};
    return largest(st, 0, heights.size() - 1);
}