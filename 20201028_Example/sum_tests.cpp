#include "../catch.hpp"
#include "sum.hpp"

TEST_CASE("sum", "[sum]")
{
    REQUIRE(sum(0, 0) == 0);
    REQUIRE(sum(1, -1) == 0);
    REQUIRE(sum(1, 1) == 2);
    REQUIRE(sum(2, 3) == 5);
}