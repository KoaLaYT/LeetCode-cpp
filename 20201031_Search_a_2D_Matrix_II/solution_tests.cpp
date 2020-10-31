#include <algorithm>

#include "../catch.hpp"
#include "solution.hpp"

struct TestCase {
    int target;
    bool expect;
};

TEST_CASE("search a 2d matrix", "[d&c]")
{
    Solution s;

    vector<vector<int>> m{
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30},
    };

    vector<int> exists{
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
        11, 12, 13, 14, 15, 16, 17, 18,
        19, 21, 22, 23, 24, 26, 30};

    for (int t = 0; t < 32; ++t) {
        auto expected = std::find(exists.begin(), exists.end(), t);
        auto result = s.searchMatrix(m, t);
        REQUIRE(result == (expected != exists.end()));
    }

    // edge cases
    vector<vector<int>> empty;
    for (int t = 0; t < 10; ++t) {
        auto result = s.searchMatrix(empty, t);
        REQUIRE(result == false);
    }

    vector<vector<int>> single{{1}};
    for (int t = 0; t < 10; ++t) {
        auto result = s.searchMatrix(single, t);
        if (t == 1) {
            REQUIRE(result == true);
        } else {
            REQUIRE(result == false);
        }
    }
}