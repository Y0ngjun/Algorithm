#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, v;
	cin >> n >> m >> v;

	map<int, set<int>> node;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;

		if (node.find(a) != node.end())
			node[a].insert(b);
		else
			node[a] = { b };

		if (node.find(b) != node.end())
			node[b].insert(a);
		else
			node[b] = { a };
	}

	vector<bool> checked(n + 1, false);

	stack<int> dfs;
	dfs.push(v);
	while (!dfs.empty())
	{
		int idx = dfs.top();
		dfs.pop();

		if (checked[idx])
			continue;

		checked[idx] = true;
		cout << idx << ' ';

		for (auto iter = node[idx].rbegin(); iter != node[idx].rend(); ++iter)
		{
			if (checked[*iter])
				continue;
			dfs.push(*iter);
		}
	}
	cout << '\n';

	checked.assign(n + 1, false);

	queue<int> bfs;
	bfs.push(v);
	while (!bfs.empty())
	{
		int idx = bfs.front();
		bfs.pop();

		if (checked[idx])
			continue;

		checked[idx] = true;
		cout << idx << ' ';

		for (auto iter = node[idx].begin(); iter != node[idx].end(); ++iter)
		{
			if (checked[*iter])
				continue;
			bfs.push(*iter);
		}
	}

	return 0;
}