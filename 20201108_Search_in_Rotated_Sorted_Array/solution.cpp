#include "solution.hpp"

int find_pivot(vector<int>& nums, int lo, int hi)
{
    while (lo <= hi) {
        int mi = lo + (hi - lo) / 2;

        if (mi - 1 >= 0 && nums[mi - 1] > nums[mi]) return mi;
        if (mi + 1 < nums.size() && nums[mi] > nums[mi + 1]) return mi + 1;

        if (nums[lo] < nums[mi]) {
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    return -1;
}

int binary_search(vector<int>& nums, int target, int lo, int hi)
{
    while (lo <= hi) {
        int mi = lo + (hi - lo) / 2;

        if (nums[mi] == target) return mi;
        if (nums[mi] > target) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    return -1;
}

int Solution::search(vector<int>& nums, int target)
{
    int p = find_pivot(nums, 0, nums.size() - 1);
    // no rotated
    if (p == -1) return binary_search(nums, target, 0, nums.size() - 1);

    if (target >= nums[0] && target <= nums[p - 1]) {
        return binary_search(nums, target, 0, p - 1);
    } else {
        return binary_search(nums, target, p, nums.size() - 1);
    }
}