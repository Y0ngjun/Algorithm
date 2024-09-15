#include <iostream>
#include <stack>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	int m;
	cin >> m;

	map<int, set<int>> net;
	for (int i = 0; i < n; ++i)
		net.insert({ i + 1, {} });

	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		net[a].insert(b);
		net[b].insert(a);
	}

	vector<bool> infect(n + 1);
	stack<int> dfs;
	dfs.push(1);

	while (!dfs.empty())
	{
		int num = dfs.top();
		dfs.pop();
		infect[num] = true;
		for (auto iter : net[num])
		{
			if (infect[iter])
				continue;
			dfs.push(iter);
		}
	}

	int count = -1;
	for (auto iter : infect)
		if (iter)
			count++;

	cout << count;

	return 0;
}