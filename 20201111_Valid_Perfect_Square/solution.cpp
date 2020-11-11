#include "solution.hpp"

bool Solution::isPerfectSquare(int num)
{
    int lo = 1;
    int hi = num;

    while (lo <= hi) {
        int mi = lo + (hi - lo) / 2;

        long long mul = (long long)mi * mi;

        if (mul == num) {
            return true;
        }

        if (mul > num) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }

    return false;
}