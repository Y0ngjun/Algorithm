// LeetCode 85. Maximal Rectangle
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int ans = 0;
        vector<int> height(m + 1, 0);

        vector<int> stk;
        stk.reserve(m + 1);

        for (int i = 0; i < n; ++i)
        {
            stk.clear();
            stk.push_back(0);

            for (int j = 1; j <= m; ++j)
            {
                height[j] = (matrix[i][j - 1] == '1' ? height[j] + 1 : 0);

                while (height[stk.back()] > height[j])
                {
                    int k = stk.back();
                    stk.pop_back();

                    int area = height[k] * (j - stk.back() - 1);
                    ans = max(ans, area);
                }

                stk.push_back(j);
            }

            while (stk.size() > 1)
            {
                int k = stk.back();
                stk.pop_back();

                int area = height[k] * (m - stk.back());
                ans = max(ans, area);
            }
        }

        return ans;
    }
};
