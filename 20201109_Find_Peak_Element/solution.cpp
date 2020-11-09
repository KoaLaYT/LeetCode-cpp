#include "solution.hpp"

int Solution::findPeakElement(vector<int>& nums)
{
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo <= hi) {
        int mi = lo + (hi - lo) / 2;

        // only one element
        if (mi - 1 < 0 && mi + 1 >= nums.size()) return mi;
        // leftmost element
        if (mi == 0) {
            if (nums[mi] > nums[mi + 1])
                return mi;
            else
                lo = mi + 1;
        }
        // rightmost element
        else if (mi == nums.size() - 1) {
            if (nums[mi - 1] < nums[mi])
                return mi;
            else
                hi = mi - 1;
        }
        // others
        else {
            if (nums[mi - 1] < nums[mi] && nums[mi] > nums[mi + 1])
                return mi;
            else if (nums[mi - 1] < nums[mi] && nums[mi] < nums[mi + 1])
                lo = mi + 1;
            else
                hi = mi - 1;
        }
    }

    throw std::exception{};
}