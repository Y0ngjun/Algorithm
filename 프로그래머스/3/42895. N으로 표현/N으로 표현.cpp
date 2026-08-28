#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number)
{
    if (number == N)
    {
        return 1;
    }

    vector<unordered_set<int>> dp(9);
    dp[1].insert(N * 1);
    dp[2].insert(N * 11);
    dp[3].insert(N * 111);
    dp[4].insert(N * 1111);
    dp[5].insert(N * 11111);
    dp[6].insert(N * 111111);
    dp[7].insert(N * 1111111);
    dp[8].insert(N * 11111111);

    for (int i = 2; i <= 8; i++)
    {
        for (int l = 1; l < i; l++)
        {
            int r = i - l;

            for (int lv : dp[l])
            {
                for (int rv : dp[r])
                {
                    dp[i].insert(lv + rv);
                    dp[i].insert(lv - rv);
                    dp[i].insert(lv * rv);

                    if (rv != 0)
                    {
                        dp[i].insert(lv / rv);
                    }
                }
            }
        }

        if (dp[i].count(number))
        {
            return i;
        }
    }

    return -1;
}

/*
* N 1개 : N
* N 2개 : NN, (N 1개) + - * / (N 1개)
* ...
*/
