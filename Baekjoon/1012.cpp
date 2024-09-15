#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int m, n, k;
		cin >> m >> n >> k;

		vector<vector<bool>> field(n, vector<bool>(m, false));
		vector<vector<bool>> checked(n, vector<bool>(m, false));

		for (int j = 0; j < k; ++j)
		{
			int x, y;
			cin >> x >> y;
			field[y][x] = true;
		}

		int count = 0;
		for (int j = 0; j < n; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				if (!field[j][k])
					continue;
				if (checked[j][k])
					continue;

				count++;
				vector<pair<int, int>> dir = { {0, 1},{1, 0},{0, -1},{-1, 0} };

				stack<pair<int, int>> dfs;
				dfs.push({ k,j });
				while (!dfs.empty())
				{
					int x = dfs.top().first;
					int y = dfs.top().second;
					dfs.pop();
					checked[y][x] = true;

					for (int j = 0; j < 4; ++j)
					{
						int nx = x + dir[j].first;
						int ny = y + dir[j].second;
						if (nx < 0 || ny < 0 || nx >= m || ny >= n)
							continue;
						if (!field[ny][nx] || checked[ny][nx])
							continue;
						dfs.push({ nx,ny });
					}
				}
			}
		}

		cout << count << '\n';
	}

	return 0;
}