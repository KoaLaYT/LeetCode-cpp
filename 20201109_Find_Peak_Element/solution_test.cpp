#include "solution.hpp"

#include <algorithm>

#include "../catch.hpp"

struct TestCase {
    vector<int> input;
    vector<int> expected;

    bool contains(int result)
    {
        return find(expected.begin(), expected.end(), result) != expected.end();
    }
};

TEST_CASE("find peak element")
{
    Solution s;

    vector<TestCase> cases{
        {{1}, {0}},
        {{1, 2, 3}, {0, 2}},
        {{1, 2, 3, 1}, {2}},
        {{1, 2, 1, 3, 5, 6, 4}, {1, 5}},
        {{3, 2, 4, 5, 6}, {0, 4}},
    };

    for (auto& c : cases) {
        auto result = s.findPeakElement(c.input);
        REQUIRE(c.contains(result));
    }
}