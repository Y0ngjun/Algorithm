#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> friends(n);
	for (int i = 0; i < m; ++i)
	{
		int f1, f2;
		cin >> f1 >> f2;
		friends[f1 - 1].push_back(f2 - 1);
		friends[f2 - 1].push_back(f1 - 1);
	}

	int ans = 0;
	int min = 2100000000;
	for (int i = 0; i < n; ++i)
	{
		int sum = 0;
		for (int j = 0; j < n; ++j)
		{
			int bacon = 0;
			vector<bool> visited(n);
			if (j == i)
				continue;
			queue<int> bfs;
			bfs.push(i);
			visited[i] = true;
			bfs.push(-1);
			while (!bfs.empty())
			{
				int f = bfs.front();
				bfs.pop();
				if (f == -1)
				{
					bfs.push(-1);
					++bacon;
					continue;
				}
				if (f == j)
					break;
				for (auto iter : friends[f])
				{
					if (visited[iter])
						continue;
					bfs.push(iter);
					visited[iter] = true;
				}
			}
			sum += bacon;
		}
		if (sum < min)
		{
			min = sum;
			ans = i;
		}
	}
	cout << ans + 1;
	return 0;
}