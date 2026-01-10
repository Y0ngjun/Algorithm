// BOJ 14517 팰린드롬 개수 구하기 (Large)
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i)
    {
        dp[i][i] = 1;
    }

    for (int length = 2; length <= n; ++length)
    {
        for (int start = 0; start + length - 1 < n; ++start)
        {
            int end = start + length - 1;

            dp[start][end] = (dp[start][end - 1] + dp[start + 1][end] + (s[start] == s[end] ? 1 : -dp[start + 1][end - 1])) % 10007;
        }
    }

    cout << (dp[0][n - 1] + 10007) % 10007;

    return 0;
}
