// LeetCode 865. Smallest Subtree with all the Deepest Nodes
using namespace std;

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int height = treeHeight(root);

        return subtreeWithAllDeepest(root, height, 1);
    }

    int treeHeight(TreeNode* root) {
        if (root->left != nullptr && root->right != nullptr)
        {
            return 1 + max(treeHeight(root->left), treeHeight(root->right));
        }
        else if (root->left != nullptr)
        {
            return 1 + treeHeight(root->left);
        }
        else if (root->right != nullptr)
        {
            return 1 + treeHeight(root->right);
        }
        else
        {
            return 1;
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root, int height, int depth)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        auto left = subtreeWithAllDeepest(root->left, height, depth + 1);
        auto right = subtreeWithAllDeepest(root->right, height, depth + 1);

        if (height == depth || left != nullptr && right != nullptr)
        {
            return root;
        }
        else if (left != nullptr)
        {
            return left;
        }
        else if (right != nullptr)
        {
            return right;
        }
        else
        {
            return nullptr;
        }
    }
};
