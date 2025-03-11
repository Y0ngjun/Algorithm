#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<vector<int>> matrix(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> matrix[i][j];

	int p;
	cin >> p;

	vector<pair<int, int>> via(p);
	for (int i = 0; i < p; ++i)
		cin >> via[i].first >> via[i].second;

	sort(via.begin(), via.end());
	via.push_back({ n, n });

	vector<vector<int>> ans(n, vector<int>(n, 0));
	ans[0][0] = matrix[0][0];
	int prev_y = 1, prev_x = 1;
	for (int i = 0; i <= p; ++i)
	{
		if (via[i].first < prev_y || via[i].second < prev_x)
		{
			cout << -1;
			return 0;
		}
		for (int j = prev_y; j < via[i].first; ++j)
			ans[j][prev_x - 1] = ans[j - 1][prev_x - 1] + matrix[j][prev_x - 1];
		for (int j = prev_x; j < via[i].second; ++j)
			ans[prev_y - 1][j] = ans[prev_y - 1][j - 1] + matrix[prev_y - 1][j];

		for (int j = prev_y; j < via[i].first; ++j)
			for (int k = prev_x; k < via[i].second; ++k)
				ans[j][k] = max(ans[j - 1][k], ans[j][k - 1]) + matrix[j][k];

		prev_y = via[i].first;
		prev_x = via[i].second;
	}
	cout << ans[n - 1][n - 1];

	return 0;
}
