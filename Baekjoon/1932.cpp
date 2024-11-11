#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> pyramid(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cin >> pyramid[i][j];
		}
	}

	// 1
	// 1 2
	// 1 2 3
	// 1 2 3 4
	// ...	아래층 숫자중 idx, idx+1 중에서만 선택할 수 있음

	// 자신이 선택됨 && 자신의 층이 마지막 층일 때의 최댓값을 저장하는 배열 dp
	vector<vector<int>> dp(n, vector<int>(n, 0));
	dp[0][0] = pyramid[0][0];
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			int upleft = 0, upright = 0;
			if (j != 0)
				upleft = dp[i - 1][j - 1];
			upright = dp[i - 1][j];
			dp[i][j] = pyramid[i][j] + max(upleft, upright);
		}
	}

	cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());

	return 0;
}