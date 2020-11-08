#include "solution.hpp"

#include <algorithm>
#include <iterator>

using It = vector<vector<int>>::iterator;

class Skyline {
public:
    Skyline(It i) : it{i} {}

    bool operator==(const Skyline& other) const { return x() == other.x(); }
    bool operator<(const Skyline& other) const { return x() < other.x(); }
    int x() const { return (*it)[0]; }
    int h() const { return (*it)[1]; }

private:
    It it;
};

void copy_left(vector<vector<int>>& merged, It left, It end)
{
    auto size = merged.size();
    merged.resize(size + distance(left, end));
    auto t = merged.begin();
    advance(t, size);
    copy(left, end, t);
}

vector<vector<int>> merge_skyline(vector<vector<int>>& leftSkyline, vector<vector<int>>& rightSkyline)
{
    It li = leftSkyline.begin();   // left index
    It ri = rightSkyline.begin();  // right index
    int lh = 0;                    // left height
    int rh = 0;                    // right height

    vector<vector<int>> merged;

    while (li != leftSkyline.end() || ri != rightSkyline.end()) {
        if (li == leftSkyline.end()) {
            copy_left(merged, ri, rightSkyline.end());
            break;
        }
        if (ri == rightSkyline.end()) {
            copy_left(merged, li, leftSkyline.end());
            break;
        }

        int nextx;

        Skyline ls{li};
        Skyline rs{ri};

        if (ls == rs) {
            lh = ls.h();
            rh = rs.h();
            nextx = ls.x();
            ++li;
            ++ri;
        } else if (ls < rs) {
            lh = ls.h();
            nextx = ls.x();
            ++li;
        } else {
            rh = rs.h();
            nextx = rs.x();
            ++ri;
        }

        int nexth = max(lh, rh);
        if (merged.empty() || merged.back()[1] != nexth) {
            merged.push_back(vector<int>{nextx, nexth});
        }
    }

    return merged;
}

vector<vector<int>> find_skyline(vector<vector<int>>& buildings, It lo, It hi)
{
    auto dist = distance(lo, hi);
    if (dist <= 0) {
        return vector<vector<int>>{};
    }

    if (dist == 1) {
        return vector<vector<int>>{{(*lo)[0], (*lo)[2]}, {(*lo)[1], 0}};
    }

    auto mi = lo;
    advance(mi, dist / 2);
    auto leftSkyline = find_skyline(buildings, lo, mi);
    auto rightSkyline = find_skyline(buildings, mi, hi);

    return merge_skyline(leftSkyline, rightSkyline);
}

vector<vector<int>> Solution::getSkyline(vector<vector<int>>& buildings)
{
    return find_skyline(buildings, buildings.begin(), buildings.end());
}