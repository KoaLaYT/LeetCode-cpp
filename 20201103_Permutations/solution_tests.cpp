#include <iostream>

#include "../catch.hpp"
#include "solution.hpp"

using namespace std;

void print(vector<vector<int>> v)
{
    cout << "[\n";
    for (auto vv : v) {
        cout << "  [ ";
        for (auto e : vv) {
            cout << e << ' ';
        }
        cout << "]\n";
    }
    cout << "]\n";
}

struct TestCase {
    vector<int> input;
    vector<vector<int>> expected;
};

TEST_CASE("permutations")
{
    Solution s;

    vector<TestCase> cases{
        {
            {1, 2},
            {
                {1, 2},
                {2, 1},
            },
        },
        {
            {1, 2, 3},
            {
                {1, 2, 3},
                {1, 3, 2},
                {2, 1, 3},
                {2, 3, 1},
                {3, 1, 2},
                {3, 2, 1},
            },
        },
        {
            {1, 2, 3, 4},
            {
                {1, 2, 3, 4},
                {1, 2, 4, 3},
                {1, 3, 2, 4},
                {1, 3, 4, 2},
                {1, 4, 2, 3},
                {1, 4, 3, 2},
                {2, 1, 3, 4},
                {2, 1, 4, 3},
                {2, 3, 1, 4},
                {2, 3, 4, 1},
                {2, 4, 1, 3},
                {2, 4, 3, 1},
                {3, 1, 2, 4},
                {3, 1, 4, 2},
                {3, 2, 1, 4},
                {3, 2, 4, 1},
                {3, 4, 1, 2},
                {3, 4, 2, 1},
                {4, 1, 2, 3},
                {4, 1, 3, 2},
                {4, 2, 1, 3},
                {4, 2, 3, 1},
                {4, 3, 1, 2},
                {4, 3, 2, 1},
            },
        }};

    for (auto& c : cases) {
        auto result = s.permute(c.input);
        REQUIRE(c.expected == result);
    }
}