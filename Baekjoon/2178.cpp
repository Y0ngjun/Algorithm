#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j)
			map[i][j] = s[j] - '0';
	}
	queue<pair<int, pair<int, int>>> bfs;
	bfs.push({ 1,{0,0} }); // d, {y, x}
	visited[0][0] = true;
	while (!bfs.empty())
	{
		int d = bfs.front().first;
		int y = bfs.front().second.first;
		int x = bfs.front().second.second;
		bfs.pop();
		vector<pair<int, int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dir[i].first;
			int nx = x + dir[i].second;
			int nd = d + 1;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (map[ny][nx] == 0)
				continue;
			if (visited[ny][nx])
				continue;
			visited[ny][nx] = true;
			bfs.push({ nd, {ny,nx} });
			if (ny == n - 1 && nx == m - 1)
				cout << nd;
		}
	}
	return 0;
}