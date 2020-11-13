#include <deque>
#include <iostream>
#include <vector>

#include "../catch.hpp"
#include "solution.hpp"

using namespace std;

namespace BST_Test {

TreeNode* from_recursive(vector<int>& input, int i)
{
    if (i >= input.size() || input[i] == -1) return nullptr;

    TreeNode* n = new TreeNode{input[i]};
    n->left = from_recursive(input, 2 * i + 1);
    n->right = from_recursive(input, 2 * i + 2);
    return n;
}

TreeNode* from(vector<int>& input)
{
    return from_recursive(input, 0);
}

vector<int> to(TreeNode* root)
{
    vector<int> res;
    deque<TreeNode*> queue;
    queue.push_back(root);
    while (queue.size() > 0) {
        auto node = queue.front();
        queue.pop_front();
        if (node == nullptr) continue;

        res.push_back(node->val);
        if (node->left != nullptr)
            queue.push_back(node->left);
        if (node->right != nullptr)
            queue.push_back(node->right);
    }
    return res;
}

};  // namespace BST_Test

struct TestCase {
    vector<int> input;
    int val;
    vector<int> expected;
};

TEST_CASE("insert into a binary search tree")
{
    Solution s;

    vector<TestCase> cases{
        {{}, 1, {1}},
        {{3}, 2, {3, 2}},
        {{40, 20, 60, 10, 30, 50, 70}, 25, {40, 20, 60, 10, 30, 50, 70, 25}},
        {{4, 2, 7, 1, 3}, 5, {4, 2, 7, 1, 3, 5}},
    };

    for (auto& c : cases) {
        auto bst = BST_Test::from(c.input);
        auto result = s.insertIntoBST(bst, c.val);
        REQUIRE(BST_Test::to(result) == c.expected);
    }
}