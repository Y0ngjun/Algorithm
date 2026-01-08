// BOJ 13250 주사위 게임
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<double> dp(N + 1);
    dp[0] = 0.0;

    for (int i = 1; i <= N; ++i)
    {
        double E = 0.0;

        for (int j = 1; j <= 6; ++j)
        {
            int need = i - j;

            if (need > 0)
            {
                E += dp[need];
            }
        }

        dp[i] = E / 6.0 + 1.0;
    }

    cout << fixed << setprecision(9) << dp[N];

    return 0;
}
