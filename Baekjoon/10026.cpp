#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> paint(n, vector<int>(n));
	vector<vector<int>> visited(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; ++j)
			paint[i][j] = str[j];
	}

	vector<int> dy = { -1,0,1,0 };
	vector<int> dx = { 0,1,0,-1 };
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (visited[i][j])
				continue;
			++count;
			int target = paint[i][j];
			stack<pair<int, int>> dfs;
			dfs.push({ i,j });
			while (!dfs.empty())
			{
				int y = dfs.top().first;
				int x = dfs.top().second;
				dfs.pop();
				if (visited[y][x])
					continue;
				visited[y][x] = true;
				for (int k = 0; k < 4; ++k)
				{
					int ny = y + dy[k];
					int nx = x + dx[k];
					if (ny < 0 || ny >= n || nx < 0 || nx >= n)
						continue;
					if (visited[ny][nx])
						continue;
					if (paint[ny][nx] != target)
						continue;
					dfs.push({ ny,nx });
				}
			}
		}
	}

	cout << count << ' ';

	count = 0;
	visited.assign(n, vector<int>(n, 0));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (visited[i][j])
				continue;
			++count;
			int target = paint[i][j];
			int target2;
			if (target == 'R')
				target2 = 'G';
			else if (target == 'G')
				target2 = 'R';
			else
				target2 = target;

			stack<pair<int, int>> dfs;
			dfs.push({ i,j });
			while (!dfs.empty())
			{
				int y = dfs.top().first;
				int x = dfs.top().second;
				dfs.pop();
				if (visited[y][x])
					continue;
				visited[y][x] = true;
				for (int k = 0; k < 4; ++k)
				{
					int ny = y + dy[k];
					int nx = x + dx[k];
					if (ny < 0 || ny >= n || nx < 0 || nx >= n)
						continue;
					if (visited[ny][nx])
						continue;
					if (paint[ny][nx] != target && paint[ny][nx] != target2)
						continue;
					dfs.push({ ny,nx });
				}
			}
		}
	}

	cout << count;

	return 0;
}