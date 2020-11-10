#include "solution.hpp"

vector<int> search_range(vector<int>& nums, int target, int lo, int hi)
{
    vector<int> result{-1, -1};
    while (lo + 1 < hi) {
        int mi = lo + (hi - lo) / 2;

        if (nums[mi] == target) {
            result[0] = mi;
            result[1] = mi;
            if (nums[mi - 1] != target && nums[mi + 1] != target) {
                return result;
            }
            vector<int> left{-1, -1};
            if (nums[mi - 1] == target) {
                result[0] = mi - 1;
                left = search_range(nums, target, lo, mi - 2);
            }
            vector<int> right{-1, -1};
            if (nums[mi + 1] == target) {
                result[1] = mi + 1;
                right = search_range(nums, target, mi + 2, hi);
            }
            if (left[0] != -1) {
                result[0] = left[0];
            }
            if (right[1] != -1) {
                result[1] = right[1];
            }
            return result;
        } else if (nums[mi] < target) {
            lo = mi;
        } else {
            hi = mi;
        }
    }

    if (nums[lo] == target) {
        result[0] = lo;
        result[1] = lo;
    }
    if (nums[hi] == target) {
        if (result[0] == -1) {
            result[0] = hi;
        }
        result[1] = hi;
    }

    return result;
}

vector<int> Solution::searchRange(vector<int>& nums, int target)
{
    if (nums.empty()) return vector<int>{-1, -1};
    return search_range(nums, target, 0, nums.size() - 1);
}