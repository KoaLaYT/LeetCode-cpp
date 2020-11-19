#ifndef SOLUTION_HPP_20201119
#define SOLUTION_HPP_20201119

#include <iostream>
#include <vector>

using namespace std;

namespace detail {

struct TreeNode {
    int val;
    int count;  // num of all children + self
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int v) : val{v},
                               count{1},
                               left{nullptr},
                               right{nullptr}
    {}
};

class BST {
public:
    explicit BST(vector<int>& nums) : root{nullptr}
    {
        for (auto n : nums)
            insert(n);
    }

    ~BST() { free(root); }

    void insert(int v) { root = insert(root, v); }
    int kth_largest(int k) { return kth_largest(root, k); }

private:
    TreeNode* root;

    TreeNode* insert(TreeNode* n, int v);
    int kth_largest(TreeNode* n, int k);
    void free(TreeNode* n);

    int left_nums(TreeNode* n)
    {
        if (!n) return 0;
        return n->left ? n->left->count : 0;
    }

    int right_nums(TreeNode* n)
    {
        if (!n) return 0;
        return n->right ? n->right->count : 0;
    }

    int total_nums(TreeNode* n)
    {
        return n ? n->count : 0;
    }
};

}  // namespace detail

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : kk{k}, bst{detail::BST{nums}} {}

    int add(int val)
    {
        bst.insert(val);
        return bst.kth_largest(kk);
    }

private:
    int kk;
    detail::BST bst;
};

#endif