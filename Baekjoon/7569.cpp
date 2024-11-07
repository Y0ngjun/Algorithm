#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n, h;
	cin >> m >> n >> h;

	queue<tuple<int, int, int, int>> bfs;
	vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m)));
	for (int k = 0; k < h; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				cin >> box[k][i][j];
				if (box[k][i][j] == 1)
					bfs.push({ k,i,j,0 });
			}
		}
	}
	vector<tuple<int, int, int>> dir = { {1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1} };
	int day = 0;
	while (!bfs.empty())
	{
		int z = get<0>(bfs.front());
		int y = get<1>(bfs.front());
		int x = get<2>(bfs.front());
		day = get<3>(bfs.front());
		bfs.pop();
		for (int i = 0; i < 6; ++i)
		{
			int nz = z + get<0>(dir[i]);
			int ny = y + get<1>(dir[i]);
			int nx = x + get<2>(dir[i]);
			int nday = day + 1;
			if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			if (box[nz][ny][nx] == 1 || box[nz][ny][nx] == -1)
				continue;
			box[nz][ny][nx] = 1;
			bfs.push({ nz,ny,nx,nday });
		}
	}

	bool isAllRed = true;
	for (int k = 0; k < h; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (box[k][i][j] == 0)
					isAllRed = false;
			}
		}
	}
	if (isAllRed)
		cout << day;
	else
		cout << -1;

	return 0;
}