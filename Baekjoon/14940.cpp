#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m));
	vector<vector<int>> answer(n, vector<int>(m, -1));
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	int start_y, start_x;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				start_y = i;
				start_x = j;
			}
			else if (map[i][j] == 0)
				answer[i][j] = 0;
		}
	}
	queue<pair<pair<int, int>, int>> bfs;
	bfs.push({ { start_y, start_x }, 0 });
	visited[start_y][start_x] = true;
	vector<pair<int, int>> dir = { {1,0},{0,1},{-1,0},{0,-1} };
	while (!bfs.empty())
	{
		int y = bfs.front().first.first;
		int x = bfs.front().first.second;
		int d = bfs.front().second;
		bfs.pop();
		answer[y][x] = d;
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
			bfs.push({ {ny,nx},nd });
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cout << answer[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
