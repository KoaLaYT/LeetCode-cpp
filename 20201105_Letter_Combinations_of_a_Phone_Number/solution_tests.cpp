#include <iostream>

#include "../catch.hpp"
#include "solution.hpp"

using namespace std;

struct TestCase {
    string input;
    vector<string> expected;
};

TEST_CASE("letter combinations of a phone number")
{
    Solution s;

    vector<TestCase> cases{
        {"", {}},
        {"2", {"a", "b", "c"}},
        {"23", {"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}},
    };

    for (auto& c : cases) {
        auto result = s.letterCombinations(c.input);
        REQUIRE(result == c.expected);
    }
}