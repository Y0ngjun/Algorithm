#include <vector>

using namespace std;

/*
* [i-1,j-1][i-1,  j]
* [i  ,j-1][  i,  j]
* dp[i][j] = board[i][j] 를 우하단으로 갖는 가장 큰 정사각형의 한 변의 길이
*/
int solution(vector<vector<int>> board)
{
    int row = board.size();
    int col = board[0].size();
    int ans = 0;

    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            if (!board[i - 1][j - 1])
                continue;

            int k = min(dp[i - 1][j], dp[i][j - 1]);

            if (!board[i - 1 - k][j - 1 - k])
                k--;

            dp[i][j] = k + 1;
            ans = max(ans, dp[i][j]);
        }
    }

    return ans * ans;
}
