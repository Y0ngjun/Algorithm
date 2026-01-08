// LeetCode 1458. Max Dot Product of Two Subsequences
#include <vector>

using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size();
        int M = nums2.size();

        vector<int> dp(M, -1e9);

        for (int i = 0; i < N; ++i)
        {
            int prev_ij = -1e9;

            for (int j = 0; j < M; ++j)
            {
                int prev_i = dp[j];

                dp[j] = nums1[i] * nums2[j];

                if (i > 0 && j > 0)
                {
                    dp[j] = max(dp[j], dp[j] + prev_ij);
                }

                if (i > 0)
                {
                    dp[j] = max(dp[j], prev_i);
                }

                if (j > 0)
                {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                prev_ij = prev_i;
            }
        }

        return dp[M - 1];
    }
};
