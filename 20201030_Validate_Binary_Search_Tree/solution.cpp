#include "solution.hpp"

#include <optional>

using std::optional;

bool is_valid_bst(TreeNode* root, optional<int> min, optional<int> max)
{
    if (root == nullptr) return true;

    if (min.has_value() && root->val <= min.value()) return false;
    if (max.has_value() && root->val >= max.value()) return false;

    optional<int> ov{root->val};

    return is_valid_bst(root->left, min, ov) && is_valid_bst(root->right, ov, max);
}

bool Solution::isValidBST(TreeNode* root)
{
    optional<int> nil;
    return is_valid_bst(root, nil, nil);
}