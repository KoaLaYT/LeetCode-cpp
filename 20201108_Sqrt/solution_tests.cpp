#include <cmath>
#include <limits>
#include <vector>

#include "../catch.hpp"
#include "solution.hpp"

using namespace std;

TEST_CASE("sqrt")
{
    Solution s;

    for (int i = 0; i < numeric_limits<int>::max(); i += 1000) {
        auto result = s.mySqrt(i);
        double expected = sqrt(i);
        REQUIRE(result == int(trunc(expected)));
    }
}