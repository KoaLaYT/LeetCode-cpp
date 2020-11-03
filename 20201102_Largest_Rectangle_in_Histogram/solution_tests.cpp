#include "../catch.hpp"
#include "solution.hpp"

using namespace std;

struct TestCase {
    vector<int> heights;
    int expected;
};

TEST_CASE("largest rectangle in histogram")
{
    Solution s;

    vector<TestCase> cases{
        {{}, 0},
        {{1}, 1},
        {{6}, 6},
        {{2, 1, 5, 6, 2, 3}, 10},
        {{2, 2, 5, 6, 2, 3}, 12},
        {{2, 1, 5, 6, 1, 3, 3, 3, 4, 1}, 12},
        {{0, 0, 0, 0, 0, 0, 0, 0, 2147483647}, 2147483647},
    };

    for (auto& c : cases) {
        auto result = s.largestRectangleArea(c.heights);
        REQUIRE(result == c.expected);
    }
}