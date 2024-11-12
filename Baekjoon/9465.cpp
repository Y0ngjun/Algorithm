#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<vector<int>> stickers(2, vector<int>(n));
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < n; ++j)
				cin >> stickers[i][j];

		vector<vector<int>> dp(2, vector<int>(n)); // 해당 스티커를 선택하고, 가장 오른쪽이라고 할 때 최댓값
		dp[0][0] = stickers[0][0];				   // 최댓값은 현재스티커값 + 반대행 idx -1, idx -2 중에 최대값.
		dp[0][1] = stickers[1][0] + stickers[0][1];
		dp[1][0] = stickers[1][0];
		dp[1][1] = stickers[0][0] + stickers[1][1];
		for (int i = 2; i < n; ++i)
		{
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + stickers[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + stickers[1][i];
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}

	return 0;
}