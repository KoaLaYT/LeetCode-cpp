#include "../catch.hpp"
#include "solution.hpp"

struct TestCase {
    vector<int> input;
    int target;
    vector<int> expected;
};

TEST_CASE("search for a range")
{
    Solution s;

    vector<TestCase> cases{
        {{}, 0, {-1, -1}},
        {{5, 7, 7, 8, 8, 10}, 8, {3, 4}},
        {{5, 7, 7, 8, 8, 10}, 6, {-1, -1}},
        {{5, 7, 7, 8, 8, 10}, 5, {0, 0}},
        {{1, 1, 2, 3, 4}, 1, {0, 1}},
        {{1, 1, 2, 4, 4}, 4, {3, 4}},
        {{1, 1, 2}, 1, {0, 1}},
    };

    for (auto& c : cases) {
        auto result = s.searchRange(c.input, c.target);
        REQUIRE(result == c.expected);
    }
}