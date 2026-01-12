// BOJ 5557 1학년
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> nums(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> nums[i];
    }

    vector<long long> dp(21, 0);
    vector<long long> temp(21, 0);
    dp[nums[0]] = 1;

    for (int i = 0; i < N - 2; ++i)
    {
        fill(temp.begin(), temp.end(), 0);

        for (int j = 0; j < 21; ++j)
        {
            if (dp[j] > 0)
            {
                int p = j + nums[i + 1];

                if (p >= 0 && p <= 20)
                {
                    temp[p] += dp[j];
                }

                int m = j - nums[i + 1];

                if (m >= 0 && m <= 20)
                {
                    temp[m] += dp[j];
                }
            }
        }

        dp.swap(temp);
    }

    cout << dp[nums[N - 1]];

    return 0;
}
