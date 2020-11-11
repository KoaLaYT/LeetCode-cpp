#include <cmath>
#include <vector>

#include "../catch.hpp"
#include "solution.hpp"

using namespace std;

struct TestCase {
    int input;
    bool expected;
};

TEST_CASE("valid perfect square")
{
    Solution s;

    vector<TestCase> cases{
        {1, true},
        {2, false},
        {4, true},
        {9, true},
        {int(pow(2, 31)) - 1, false},
    };

    for (auto& c : cases) {
        auto result = s.isPerfectSquare(c.input);
        REQUIRE(result == c.expected);
    }
}