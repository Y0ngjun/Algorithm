#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<bool>> apts(n, vector<bool>(n, false));
	vector<vector<bool>> visited(n, vector<bool>(n, false));
	vector<int> apt_cnts;
	vector<pair<int, int>> dir = { {0,1},{1,0},{0,-1},{-1,0} };
	for (int i = 0; i < n; ++i)
	{
		string apt;
		cin >> apt;
		for (int j = 0; j < n; ++j)
			apts[i][j] = apt[j] - '0';
	}
	int vil_cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!apts[i][j]) // 아파트가 없다면
				continue;
			if (visited[i][j]) // 방문경험이 있다면
				continue;
			++vil_cnt;
			int apt_cnt = 0;
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
				++apt_cnt;
				for (int k = 0; k < 4; ++k)
				{
					int ny = y + dir[k].first;
					int nx = x + dir[k].second;
					if (ny < 0 || ny >= n || nx < 0 || nx >= n)
						continue;
					if (!apts[ny][nx])
						continue;
					if (visited[ny][nx])
						continue;
					dfs.push({ ny,nx });
				}
			}
			apt_cnts.push_back(apt_cnt);
		}
	}
	sort(apt_cnts.begin(), apt_cnts.end());
	cout << vil_cnt << '\n';
	for (int i = 0; i < apt_cnts.size(); ++i)
		cout << apt_cnts[i] << '\n';
	return 0;
}
