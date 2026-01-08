// LeetCode 1339. Maximum Product of Splitted Binary Tree
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxProduct(TreeNode* root) {
        // max {(sum - x) * x} -> x = 1/2 * sum

        int sum = 0;
        int x = 0;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();

            sum += node->val;

            if (node->left != nullptr)
            {
                q.push(node->left);
            }

            if (node->right != nullptr)
            {
                q.push(node->right);
            }
        }

        subSum(root, x, sum);

        return (1LL * (sum - x) * x) % 1000000007;
    }

    int subSum(TreeNode* root, int& x, int sum)
    {
        if (root == nullptr)
        {
            return 0;
        }

        int l = subSum(root->left, x, sum);
        int r = subSum(root->right, x, sum);
        int ret = l + r + root->val;

        if (abs(sum - ret * 2) < abs(sum - x * 2))
        {
            x = ret;
        }

        return ret;
    }
};
