#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode *root)
{
    if (root == nullptr)
        return;
    dfs(root->left);
    dfs(root->right);
}

TreeNode *MirrorTree(TreeNode *root)
{
    if (root == nullptr)
        return nullptr;
    TreeNode *right = MirrorTree(root->left);
    root->left = MirrorTree(root->right);
    root->right = right;
    return root;
}

void preorder(TreeNode *root)
{
    if (root == nullptr)
        return;
    cout << root->val << endl;
    preorder(root->left);
    preorder(root->right);
}

void idfs(TreeNode *root)
{
    if (root == nullptr)
        return;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {
        TreeNode *tmp = st.top();
        st.pop();
        cout << tmp->val << endl;
        if (tmp->right != nullptr)
            st.push(tmp->right);
        if (tmp->left != nullptr)
            st.push(tmp->left);
    }
}

void LevelOrder(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
    int lvl = 0;
    while (!q.empty())
    {
        int count = q.size();
        cout << "Level " << lvl << ": ";
        while (count > 0)
        {
            TreeNode *node = q.front();
            cout << node->val << " ";
            q.pop();
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
            count--;
        }
        cout << endl;
        lvl++;
    }
}

int main()
{
    TreeNode *rlsubTree = new TreeNode(3, NULL, NULL);
    TreeNode *rrsubTree = new TreeNode(5, NULL, NULL);
    TreeNode *llsubTree = new TreeNode(4, NULL, NULL);
    TreeNode *lrsubTree = new TreeNode(6, NULL, NULL);

    TreeNode *lsubTree = new TreeNode(10, llsubTree, lrsubTree);
    TreeNode *rsubTree = new TreeNode(7, rlsubTree, rrsubTree);

    TreeNode *root = new TreeNode(15, lsubTree, rsubTree);

    preorder(root);
    cout << "\nIDFS -\n";
    idfs(root);
    cout << "\nLevelOrder -\n";
    LevelOrder(root);
    cout << endl;
    return 0;
}

//       15
//   10      7
// 4   6   3   5
