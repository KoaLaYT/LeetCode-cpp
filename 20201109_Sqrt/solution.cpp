#include "solution.hpp"

int Solution::mySqrt(int x)
{
    int lo = 0;
    int hi = x;

    while (lo <= hi) {
        int v = lo + (hi - lo) / 2;

        auto result = (long long)v * v - x;

        if (result == 0) {
            return v;
        } else if (result > 0) {
            hi = v - 1;
        } else {
            lo = v + 1;
        }
    }

    return hi;
}