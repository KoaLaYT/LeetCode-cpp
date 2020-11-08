#include "solution.hpp"

int binary_search(vector<int>& nums, int target, int lo, int hi)
{
    if (lo > hi) return -1;

    int mi = lo + (hi - lo) / 2;
    if (nums[mi] == target) {
        return mi;
    }
    if (nums[mi] > target) {
        return binary_search(nums, target, lo, mi - 1);
    } else {
        return binary_search(nums, target, mi + 1, hi);
    }
}

int Solution::search(vector<int>& nums, int target)
{
    return binary_search(nums, target, 0, nums.size() - 1);
}