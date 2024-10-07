#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<char>> campus(n, vector<char>(m));
	vector<vector<bool>> visited(n, vector<bool>(m));
	int y, x;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; ++j)
		{
			campus[i][j] = str[j];
			if (str[j] == 'I')
			{
				y = i;
				x = j;
			}
		}
	}

	int count = 0;
	stack<pair<int, int>> dfs;
	dfs.push({ y, x });
	while (!dfs.empty())
	{
		int Y = dfs.top().first;
		int X = dfs.top().second;
		dfs.pop();
		if (visited[Y][X])
			continue;
		visited[Y][X] = true;
		if (campus[Y][X] == 'P')
			++count;
		for (int i = 0; i < 4; ++i)
		{
			int NY, NX;
			switch (i)
			{
			case 0:
				NY = Y + 1;
				NX = X;
				break;
			case 1:
				NY = Y;
				NX = X + 1;
				break;
			case 2:
				NY = Y - 1;
				NX = X;
				break;
			case 3:
				NY = Y;
				NX = X - 1;
				break;
			}
			if (NY < 0 || NY >= n || NX < 0 || NX >= m)
				continue;
			if (campus[NY][NX] == 'X')
				continue;
			if (visited[NY][NX])
				continue;
			dfs.push({ NY, NX });
		}
	}
	if (count)
		cout << count;
	else
		cout << "TT";

	return 0;
}