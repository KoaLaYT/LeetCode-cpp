#include "solution.hpp"

#include <algorithm>

struct PreConditionNotHold : public std::exception {
};

int find_pivot(vector<int>& nums)
{
    int lo = 1;  // mi - 1 always valid
    int hi = nums.size() - 1;

    while (lo < hi) {  // mi + 1 always valid
        int mi = lo + (hi - lo) / 2;

        if (nums[mi] > nums[mi + 1]) {
            return mi + 1;
        }
        if (nums[mi - 1] > nums[mi]) {
            return mi;
        }

        if (nums[mi] < nums[lo - 1]) {
            hi = mi - 1;
        } else if (nums[mi] > nums[hi]) {
            lo = mi + 1;
        } else {
            // The assumption is the nums vector
            // must rotated at some index,
            // so this branch should never reached
            // throw PreConditionNotHold{};
            return 0;
        }
    }

    // nums.size() == 1 || 2
    return hi;
}

int Solution::findMin(vector<int>& nums)
{
    int p = find_pivot(nums);

    return min(nums[0], nums[p]);
}