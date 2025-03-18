#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	queue<int> bfs;
	vector<bool> is_trusy(n);
	int trusy_num;
	cin >> trusy_num;
	for (int i = 0; i < trusy_num; ++i)
	{
		int trusy;
		cin >> trusy;
		bfs.push(trusy - 1);
		is_trusy[trusy - 1] = true;
	}


	vector<vector<int>> parties(m);
	vector<vector<int>> visited_parties(n);
	for (int i = 0; i < m; ++i)
	{
		int people_num;
		cin >> people_num;
		for (int j = 0; j < people_num; ++j)
		{
			int person;
			cin >> person;
			parties[i].push_back(person - 1);
			visited_parties[person - 1].push_back(i);
		}
	}

	while (!bfs.empty())
	{
		int person = bfs.front();
		bfs.pop();
		for (auto party : visited_parties[person])
		{
			for (auto p : parties[party])
			{
				if (is_trusy[p])
					continue;
				is_trusy[p] = true;
				bfs.push(p);
			}
		}
	}

	int ans = 0;
	for (auto party : parties)
	{
		bool is_count = true;
		for (auto p : party)
		{
			if (is_trusy[p])
			{
				is_count = false;
				break;
			}
		}
		if (is_count)
			++ans;
	}

	cout << ans;

	return 0;
}