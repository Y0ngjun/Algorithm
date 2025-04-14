#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> paths(m, vector<int>(3));
	for (int i = 0; i < m; ++i)
		cin >> paths[i][0] >> paths[i][1] >> paths[i][2];

	sort(paths.begin(), paths.end(), [](const auto& a, const auto& b) {
		return a[2] < b[2];
		});

	vector<int> parent(n + 1);
	for (int i = 1; i <= n; ++i)
		parent[i] = i;
	int idx = 0;
	int ans = 0;
	for (int i = 0; i < n - 2; ++i)
	{
		while (true)
		{
			int left = paths[idx][0];
			int right = paths[idx][1];
			while (parent[left] != left)
				left = parent[left];
			while (parent[right] != right)
				right = parent[right];
			if (left == right)
				++idx;
			else
			{
				parent[max(left, right)] = min(left, right);
				break;
			}
		}
		ans += paths[idx][2];
	}

	cout << ans;

	return 0;
}