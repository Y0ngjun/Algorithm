#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> line(n + 1);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		line[a].push_back(b);
		line[b].push_back(a);
	}

	int count = 0;
	vector<bool> checked(n + 1);
	for (int i = 1; i <= n; ++i)
	{
		if (checked[i])
			continue;
		count++;
		stack<int> dfs;
		checked[i] = true;
		dfs.push(i);
		while (!dfs.empty())
		{
			int num = dfs.top();
			dfs.pop();
			checked[num] = true;
			for (int j : line[num])
			{
				if (!checked[j])
				{
					checked[j] = true;
					dfs.push(j);
				}
			}
		}
	}
	cout << count;
	return 0;
}