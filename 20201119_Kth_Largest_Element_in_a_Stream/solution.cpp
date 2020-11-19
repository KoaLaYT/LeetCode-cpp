#include "solution.hpp"

namespace detail {

TreeNode* BST::insert(TreeNode* n, int v)
{
    if (!n) return new TreeNode(v);
    if (v < n->val) {
        n->left = insert(n->left, v);
    } else if (v > n->val) {
        n->right = insert(n->right, v);
    }
    n->count += 1;
    return n;
}

// PREREQUEST: n->count >= k
// so n will never be nullptr
int BST::kth_largest(TreeNode* n, int k)
{
    int total = total_nums(n);
    int left = left_nums(n);
    int right = right_nums(n);
    int current = total - left - right;

    if (current >= k - right && right < k) {
        return n->val;
    }
    if (right >= k) {
        return kth_largest(n->right, k);
    } else {
        return kth_largest(n->left, k - right - current);
    }
}

void BST::free(TreeNode* n)
{
    if (n->left) free(n->left);
    if (n->right) free(n->right);
    delete n;
}

};  // namespace detail