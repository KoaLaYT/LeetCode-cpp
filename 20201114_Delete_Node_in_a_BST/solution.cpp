#include "solution.hpp"

#include <utility>

using namespace std;
using NodePair = pair<TreeNode*, TreeNode*>;

NodePair find(NodePair pair, int key)
{
    if (!pair.first || pair.first->val == key) return pair;

    if (key < pair.first->val) {
        return find(make_pair(pair.first->left, pair.first), key);
    } else {
        return find(make_pair(pair.first->right, pair.first), key);
    }
}

TreeNode* find_right_most(TreeNode* current, TreeNode* parent)
{
    while (current->right) {
        parent = current;
        current = current->right;
    }
    parent->right = current->left;
    return current;
}

TreeNode* Solution::deleteNode(TreeNode* root, int key)
{
    auto pair = find(make_pair(root, nullptr), key);
    auto current = pair.first;
    auto parent = pair.second;
    // did not find the key
    if (!current) return root;
    // did find the key, split to three conditions
    // [1] this node has no children
    TreeNode* new_node = nullptr;
    if (!current->left && !current->right) {
        // do nothing
    }
    // [2] this node has one child
    else if (current->left && !current->right) {
        new_node = current->left;
    } else if (!current->left && current->right) {
        new_node = current->right;
    }
    // [3] this node has two child
    else if (!current->left->right) {
        current->left->right = current->right;
        new_node = current->left;
    } else {
        new_node = find_right_most(current->left, current);
        new_node->left = current->left;
        new_node->right = current->right;
    }

    if (!parent) return new_node;
    if (parent->left == current) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
    return root;
}