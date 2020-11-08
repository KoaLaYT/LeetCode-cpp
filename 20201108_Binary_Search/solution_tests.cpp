#include "../catch.hpp"
#include "solution.hpp"

struct TestCase {
    vector<int> input;
    int target;
    int expected;
};

TEST_CASE("binary search")
{
    Solution s;

    vector<TestCase> cases{
        {{}, 1, -1},
        {{-1, 0, 3, 5, 9, 12}, 9, 4},
        {{-1, 0, 3, 5, 9, 12}, -1, 0},
        {{-1, 0, 3, 5, 9, 12}, 12, 5},
        {{-1, 0, 3, 5, 9, 12}, -2, -1},
        {{-1, 0, 3, 5, 9, 12}, 14, -1},
        {{-1, 0, 3, 5, 9, 12}, 2, -1},
    };

    for (auto& c : cases) {
        auto result = s.search(c.input, c.target);
        REQUIRE(result == c.expected);
    }
}