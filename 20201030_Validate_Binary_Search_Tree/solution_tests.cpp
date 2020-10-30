#include <iostream>
#include <vector>

#include "../catch.hpp"
#include "solution.hpp"

using namespace std;

// build a bst from a vec
// such as [2,1,3,-1,-1,4,5], where -1 means nullptr
TreeNode* build_bst(const vector<int>& v)
{
    vector<TreeNode*> nodes(v.size());
    for (auto i = 0; i < v.size(); ++i) {
        if (v[i] == -1) {
            nodes[i] = nullptr;
        } else {
            nodes[i] = new TreeNode(v[i]);
        }
    }
    for (auto i = 0; i < v.size(); ++i) {
        auto left = 2 * i + 1;
        auto right = 2 * i + 2;
        if (left < v.size()) {
            nodes[i]->left = nodes[left];
        }
        if (right < v.size()) {
            nodes[i]->right = nodes[right];
        }
    }
    return nodes[0];
}

struct TestCase {
    vector<int> nodes;
    bool expect;
};

TEST_CASE("is valid bst", "[bst]")
{
    Solution s;

    vector<TestCase> cases{
        {{-1}, true},
        {{2, 1, 3}, true},
        {{2, 1, 3, -1, -1, 4, 5}, false},
        {{10, 5, 15, -1, -1, 6, 20}, false},
    };

    for (auto& c : cases) {
        auto bst = build_bst(c.nodes);
        auto result = s.isValidBST(bst);
        REQUIRE(result == c.expect);
    }
}