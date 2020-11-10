#include "../catch.hpp"
#include "solution.hpp"

struct TestCase {
    vector<int> input;
    int k;
    int x;
    vector<int> expected;
};

TEST_CASE("find k closest elements")
{
    Solution s;

    vector<TestCase> cases{
        {{1}, 1, 3, {1}},
        {{1, 2, 3, 4, 5}, 4, 3, {1, 2, 3, 4}},
        {{1, 2, 3, 4, 5}, 4, -1, {1, 2, 3, 4}},
        {{1, 3, 5, 100, 101}, 3, 2, {1, 3, 5}},
        {{1, 1, 1, 1, 2}, 3, 2, {1, 1, 2}},
    };

    for (auto& c : cases) {
        auto result = s.findClosestElements(c.input, c.k, c.x);
        REQUIRE(result == c.expected);
    }
}