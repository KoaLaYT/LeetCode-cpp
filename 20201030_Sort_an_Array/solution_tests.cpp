#include <algorithm>

#include "../catch.hpp"
#include "solution.hpp"

Solution s;

TEST_CASE("merge sort", "[sort]")
{
    vector<vector<int>> cases{
        {},
        {1},
        {5, 2, 3, 1},
        {5, 1, 1, 2, 0, 0},
        {5, 1, 1, 2, 0},
    };

    for (auto& c : cases) {
        auto sorted = s.sortArray(c);
        REQUIRE(std::is_sorted(sorted.begin(), sorted.end()));
    }
}