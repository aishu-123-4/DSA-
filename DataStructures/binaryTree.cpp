#include <iostream>
#include <vector>
#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void dfs(TreeNode *root) {
    if (root == nullptr) return;
    dfs(root->left);
    dfs(root->right);
}

TreeNode* MirrorTree(TreeNode *root) {
    if (root == nullptr) return nullptr;
    TreeNode *right = MirrorTree(root->left);
    root->left = MirrorTree(root->right);
    root->right = right;
    return root;
}


int main() {
    return 0;
}