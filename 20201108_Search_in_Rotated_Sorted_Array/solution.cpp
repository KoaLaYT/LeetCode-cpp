#include "solution.hpp"

int Solution::search(vector<int>& nums, int target)
{
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi) {
        int mi = lo + (hi - lo) / 2;

        if (nums[mi] == target) return mi;

        if (nums[mi] > target) {
            if (nums[lo] <= target ||
                (mi - 1 > lo && nums[mi - 1] < nums[lo])) {
                hi = mi - 1;
            } else {
                lo = mi + 1;
            }
        } else {
            if (nums[hi] >= target ||
                (mi + 1 < hi && nums[mi + 1] > nums[hi])) {
                lo = mi + 1;
            } else {
                hi = mi - 1;
            }
        }
    }

    return -1;
}