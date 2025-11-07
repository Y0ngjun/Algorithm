// BOJ 2193 이친수
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// dp[i][j] = i자리 이친수 중 j로 끝나는 이친수의 개수
	// dp[i][0] = dp[i-1][0] + dp[i-1][1], dp[i][1] = dp[i-1][0];
	vector<vector<long long>> dp(n + 1, vector<long long>(2));
	dp[1][0] = 0;
	dp[1][1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	cout << dp[n][0] + dp[n][1];

	return 0;
}