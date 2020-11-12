#ifndef SOLUTION_HPP_20201112
#define SOLUTION_HPP_20201112

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode* root)
    {
        pushLeftNodes(root);
    }

    /** @return the next smallest number */
    int next()
    {
        auto top = s.back();
        s.pop_back();
        pushLeftNodes(top->right);
        return top->val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !s.empty(); }

private:
    vector<TreeNode*> s;

    void pushLeftNodes(TreeNode* node)
    {
        while (node != nullptr) {
            s.push_back(node);
            node = node->left;
        }
    }
};

#endif