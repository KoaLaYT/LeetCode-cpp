#include "../catch.hpp"
#include "solution.hpp"

vector<int> iter(BSTIterator& i)
{
    vector<int> res;
    while (i.hasNext()) {
        res.push_back(i.next());
    }
    return res;
}

TEST_CASE("binary search tree iterator")
{
    TreeNode n1{3};
    TreeNode n2{9};
    TreeNode n3{20};
    TreeNode n4{15, &n2, &n3};
    TreeNode root{7, &n1, &n4};

    BSTIterator bsti{&root};

    REQUIRE(iter(bsti) == vector<int>{3, 7, 9, 15, 20});
}