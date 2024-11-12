#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> items(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> items[i].first >> items[i].second;

	vector<vector<int>> dp(n + 1, vector<int>(k + 1));
	for (int item = 1; item <= n; ++item)
	{
		for (int bag = 1; bag <= k; ++bag)
		{
			int weight = items[item].first;
			int value = items[item].second;
			if (weight <= bag)
				dp[item][bag] = max(dp[item - 1][bag], dp[item - 1][bag - weight] + value);
			else
				dp[item][bag] = dp[item - 1][bag];
		}
	}

	cout << dp[n][k];

	return 0;
}