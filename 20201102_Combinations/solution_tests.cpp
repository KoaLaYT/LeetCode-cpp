#include <iostream>

#include "../catch.hpp"
#include "solution.hpp"

using namespace std;

void print(const vector<vector<int>>& v)
{
    cout << "---------\n";
    for (const auto& e : v) {
        cout << "[ ";
        for (const auto& ee : e) {
            cout << ee << ' ';
        }
        cout << "]\n";
    }
}

struct TestCase {
    int n;
    int k;
    vector<vector<int>> expected;
};

TEST_CASE("combination", "[backtrace]")
{
    Solution s;

    vector<TestCase> cases{
        {1, 1, {{1}}},
        {4, 2, {{1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}}},
        {4, 3, {{1, 2, 3}, {1, 2, 4}, {1, 3, 4}, {2, 3, 4}}},
    };

    for (auto& c : cases) {
        auto result = s.combine(c.n, c.k);
        REQUIRE(result == c.expected);
        print(result);
    }
}
