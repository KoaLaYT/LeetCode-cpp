#include <deque>
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
    int key;
    vector<int> expected;
};

TEST_CASE("delete node in a bst")
{
    Solution s;

    vector<TestCase> cases{
        {{8, 4, 11, 2, 6, 9, 12, 1, 3, 5, 7}, 8, {7, 4, 11, 2, 6, 9, 12, 1, 3, 5}},
        {{8, 4, 11, 2, 6, 9, 12, 1, 3, 5, 7}, 4, {8, 3, 11, 2, 6, 9, 12, 1, 5, 7}},
        {{8, 4, 11, 2, 6, 9, 12, 1, 3, 5, 7}, 1, {8, 4, 11, 2, 6, 9, 12, 3, 5, 7}},
        {{8, 4, 11, 2, 6, 9, 12, 1, 3, 5, 7}, 11, {8, 4, 9, 2, 6, 12, 1, 3, 5, 7}},
        {{}, 1, {}},
        {{2, 1, 3}, 4, {2, 1, 3}},
        {{2, 1, 3}, 2, {1, 3}},
    };

    for (auto& c : cases) {
        auto result = s.deleteNode(BST_Test::from(c.input), c.key);
        REQUIRE(BST_Test::to(result) == c.expected);
    }
}