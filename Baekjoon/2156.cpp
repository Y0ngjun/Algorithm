#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> wines(n);
	for (int i = 0; i < n; ++i)
		cin >> wines[i];

	vector<vector<int>> dp(n, vector<int>(3));
	dp[0][0] = 0;
	dp[0][1] = dp[0][2] = wines[0];

	for (int i = 1; i < n; ++i)
	{
		dp[i][0] = *max_element(dp[i - 1].begin(), dp[i - 1].end());
		dp[i][1] = max(dp[i][0], dp[i - 1][0] + wines[i]);
		dp[i][2] = max(dp[i][1], dp[i - 1][1] + wines[i]);
	}

	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());

	return 0;
}