#include "../catch.hpp"
#include "solution.hpp"

struct TestCase {
    vector<vector<int>> buildings;
    vector<vector<int>> expected;
};

TEST_CASE("the skyline problem")
{
    Solution s;

    vector<TestCase> cases{
        {{},
         {}},
        {{
             {2, 9, 10},
             {3, 7, 15},
             {5, 12, 12},
             {15, 20, 10},
             {19, 24, 8},
         },
         {
             {2, 10},
             {3, 15},
             {7, 12},
             {12, 0},
             {15, 10},
             {20, 8},
             {24, 0},
         }},
    };

    for (auto& c : cases) {
        auto result = s.getSkyline(c.buildings);
        REQUIRE(result == c.expected);
    }
}