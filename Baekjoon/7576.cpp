#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;

	queue<pair<pair<int, int>, int>> bfs;
	vector<vector<int>> box(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
				bfs.push({ {i,j},0 });
		}
	}

	vector<pair<int, int>> dir = { {-1,0},{0,1},{1,0},{0,-1} };
	int day = 0;
	while (!bfs.empty())
	{
		int y = bfs.front().first.first;
		int x = bfs.front().first.second;
		day = bfs.front().second;
		bfs.pop();
		for (int i = 0; i < 4; ++i)
		{
			int ny = y + dir[i].first;
			int nx = x + dir[i].second;
			int nday = day + 1;
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (box[ny][nx] == 1 || box[ny][nx] == -1)
				continue;
			box[ny][nx] = 1;
			bfs.push({ {ny,nx},nday });
		}
	}

	bool isAllRed = true;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (box[i][j] == 0)
				isAllRed = false;
		}
	}
	if (isAllRed)
		cout << day;
	else
		cout << -1;

	return 0;
}