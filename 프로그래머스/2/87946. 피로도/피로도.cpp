#include <vector>
#include <algorithm>

using namespace std;

int popcount(int bitmask)
{
    int ret = 0;

    for (int i = 1; i < 256; i <<= 1)
    {
        if (bitmask & i) ret++;
    }

    return ret;
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = 0;
    int n = dungeons.size();
    int m = (1 << n);

    vector<int> dp(m, -1);
    dp[0] = k;

    for (int i = 0; i < m; i++)
    {
        if (dp[i] == -1) continue;

        for (int j = 0; j < n; j++)
        {
            int bit = (1 << j);

            if (i & bit || dungeons[j][0] > dp[i]) continue;

            if (dp[i | bit] == -1 || dp[i | bit] < dp[i] - dungeons[j][1])
            {
                dp[i | bit] = dp[i] - dungeons[j][1];
            }
        }

        answer = max(answer, popcount(i));
    }

    return answer;
}
