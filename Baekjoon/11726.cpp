#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<long long> dp(n);
	dp[0] = 1, dp[1] = 2;
	for (int i = 2; i < n; ++i)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	cout << dp[n - 1] % 10007;

	return 0;
}