#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int>> room(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> room[i][j];

	queue<pair<pair<int, int>, int>> bfs;
	bfs.push({ {0,1},1 }); // x, y, pos
	int count = 0;
	while (!bfs.empty())
	{
		int y = bfs.front().first.first;
		int x = bfs.front().first.second;
		int pos = bfs.front().second;
		bfs.pop();

		if (y == n - 1 && x == n - 1)
			++count;

		switch (pos)
		{
		case 1: // 가로
			if (x + 1 < n && room[y][x + 1] == 0)
			{
				bfs.push({ {y,x + 1},1 });
				if (y + 1 < n && room[y + 1][x] == 0 && room[y + 1][x + 1] == 0)
					bfs.push({ {y + 1,x + 1},3 });
			}
			break;
		case 2: // 세로
			if (y + 1 < n && room[y + 1][x] == 0)
			{
				bfs.push({ {y + 1,x},2 });
				if (x + 1 < n && room[y][x + 1] == 0 && room[y + 1][x + 1] == 0)
					bfs.push({ {y + 1,x + 1},3 });
			}
			break;
		case 3: // 대각선
			if (x + 1 < n && room[y][x + 1] == 0)
				bfs.push({ {y,x + 1},1 });
			if (y + 1 < n && room[y + 1][x] == 0)
			{
				bfs.push({ {y + 1,x},2 });
				if (x + 1 < n && room[y][x + 1] == 0 && room[y + 1][x + 1] == 0)
					bfs.push({ {y + 1,x + 1},3 });
			}
			break;
		}
	}

	cout << count;

	return 0;
}