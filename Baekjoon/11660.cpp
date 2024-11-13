#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> dp(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> dp[i][j];
			if (i > 0 && j > 0)
				dp[i][j] += dp[i][j - 1] + dp[i - 1][j] - dp[i - 1][j - 1];
			else if (i > 0)
				dp[i][j] += dp[i - 1][j];
			else if (j > 0)
				dp[i][j] += dp[i][j - 1];
		}
	}

	for (int i = 0; i < m; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1;
		--y1;
		--x2;
		--y2;

		//		x1-1y1-1    x1-1y2
		//			    x1y1
		//	      x2y1-1	x2y2
		int answer = dp[x2][y2];
		if (x1 > 0 && y1 > 0)
			answer -= dp[x2][y1 - 1] + dp[x1 - 1][y2] - dp[x1 - 1][y1 - 1];
		else if (x1 > 0)
			answer -= dp[x1 - 1][y2];
		else if (y1 > 0)
			answer -= dp[x2][y1 - 1];

		cout << answer << '\n';
	}

	return 0;
}