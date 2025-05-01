#include <iostream>
#include <vector>

using namespace std;

void make_line(int af, const vector<vector<int>>& before, vector<bool>& visited)
{
	if (visited[af])
		return;

	if (before[af].size() == 0)
	{
		cout << af + 1 << ' ';
		visited[af] = true;
		return;
	}

	for (int be : before[af])
		make_line(be, before, visited);
	cout << af + 1 << ' ';
	visited[af] = true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> before(n);
	for (int i = 0; i < m; ++i)
	{
		int be, af;
		cin >> be >> af;
		before[af - 1].push_back(be - 1);
	}
	vector<bool> visited(n, false);
	for (int i = 0; i < n; ++i)
		make_line(i, before, visited);

	return 0;
}