#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle)
{
    int n = triangle.size();

    vector<vector<int>> dp(2, vector<int>(n, 0));
    dp[0][0] = triangle[0][0];

    for (int i = 0; i < n - 1; i++)
    {
        dp[1].assign(n, 0);
        for (int j = 0; j <= i; j++)
        {
            dp[1][j] = max(dp[1][j], dp[0][j] + triangle[i + 1][j]);
            dp[1][j + 1] = max(dp[1][j + 1], dp[0][j] + triangle[i + 1][j + 1]);
        }
        dp[0].swap(dp[1]);
    }

    return *max_element(dp[0].begin(), dp[0].end());
}
