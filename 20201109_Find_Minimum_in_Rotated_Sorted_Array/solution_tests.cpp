#include "../catch.hpp"
#include "solution.hpp"

struct TestCase {
    vector<int> input;
    int expected;
};

TEST_CASE("find min in rotated sorted array")
{
    Solution s;

    vector<TestCase> cases{
        {{1}, 1},
        {{2, 1}, 1},
        {{1, 2}, 1},
        {{1, 2, 3, 4, 5}, 1},
        {{2, 3, 1}, 1},
        {{3, 4, 5, 1, 2}, 1},
        {{4, 5, 6, 7, 0, 1, 2}, 0},
        {{5, 6, 7, 10, 1, 2}, 1},
    };

    for (auto& c : cases) {
        auto result = s.findMin(c.input);
        REQUIRE(result == c.expected);
    }
}