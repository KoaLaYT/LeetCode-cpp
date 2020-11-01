#include <vector>

#include "../catch.hpp"
#include "solution.hpp"

using namespace std;

struct TestCase {
    int input;
    int expected;
};

TEST_CASE("n-queens problem", "[backtrace]")
{
    Solution s;

    vector<TestCase> cases{
        {0, 0},
        {1, 1},
        {2, 0},
        {3, 0},
        {4, 2},
        {5, 10},
        {6, 4},
        {7, 40},
        {8, 92},
        {9, 352},
        {10, 724},
        {11, 2680},
        {12, 14200},
        // too slow to run
        // {13, 73712},
        // {14, 365596},
        // {15, 2279184},
    };

    for (auto& c : cases) {
        auto result = s.totalNQueens(c.input);
        REQUIRE(result == c.expected);
    }
}