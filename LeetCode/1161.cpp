// LeetCode 1161. Maximum Level Sum of a Binary Tree
#include <queue>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> bfs;
        bfs.push({ root, 1 });

        int ret = -1;
        int maxSum = INT_MIN;
        int currSum = 0;

        while (!bfs.empty())
        {
            auto [node, level] = bfs.front();
            bfs.pop();

            currSum += node->val;

            if (bfs.empty() || bfs.front().second != level)
            {
                if (currSum > maxSum)
                {
                    ret = level;
                    maxSum = currSum;
                }

                currSum = 0;
            }

            if (node->left != nullptr)
            {
                bfs.push({ node->left, level + 1 });
            }

            if (node->right != nullptr)
            {
                bfs.push({ node->right, level + 1 });
            }
        }

        return ret;
    }
};
