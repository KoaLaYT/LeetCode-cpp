#include "../catch.hpp"
#include "solution.hpp"

struct TestCase {
    vector<char> input;
    char target;
    char expected;
};

TEST_CASE("find smallest letter greater than target")
{
    Solution s;

    vector<TestCase> cases{
        {{'a', 'a', 'a', 'b'}, 'a', 'b'},
        {{'a', 'a', 'a', 'c'}, 'b', 'c'},
        {{'a', 'a', 'a', 'c'}, 'c', 'a'},
        {{'c', 'f', 'j'}, 'a', 'c'},
        {{'c', 'f', 'j'}, 'c', 'f'},
        {{'c', 'f', 'j'}, 'd', 'f'},
        {{'c', 'f', 'j'}, 'f', 'j'},
        {{'c', 'f', 'j'}, 'g', 'j'},
        {{'c', 'f', 'j'}, 'j', 'c'},
        {{'c', 'f', 'j'}, 'k', 'c'},
    };

    for (auto& c : cases) {
        auto result = s.nextGreatestLetter(c.input, c.target);
        REQUIRE(result == c.expected);
    }
}