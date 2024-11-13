#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;
int ans = 2100000000;
void bf(int start, int end, int m, vector<int>& count, vector<pair<int, int>>& houses, vector<pair<int, int>>& stores, vector<vector<int>>& costs)
{
	if (count.size() == m)
	{
		vector<bool> exist(stores.size());
		for (int i = 0; i < count.size(); ++i)
			exist[count[i]] = true;

		int cost = 0;
		for (int i = 0; i < houses.size(); ++i)
		{
			int min_store = -1;
			int min_dist = 2100000000;
			for (int j = 0; j < stores.size(); ++j)
			{
				if (exist[j] && costs[i][j] < min_dist)
				{
					min_dist = costs[i][j];
					min_store = j;
				}
			}
			cost += min_dist;
		}
		if (cost < ans)
			ans = cost;
	}
	else
	{
		for (int i = start; i < end; ++i)
		{
			count.push_back(i);
			bf(i + 1, end, m, count, houses, stores, costs); // 다음 가게 선택
			count.pop_back();
		}
	}
}

int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> houses;
	vector<pair<int, int>> stores;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			int num;
			cin >> num;
			if (num == 1)
				houses.push_back({ i,j });
			else if (num == 2)
				stores.push_back({ i,j });
		}

	vector<vector<int>> costs(houses.size(), vector<int>(stores.size()));
	for (int i = 0; i < houses.size(); ++i)
	{
		for (int j = 0; j < stores.size(); ++j)
		{
			costs[i][j] = abs(houses[i].first - stores[j].first) + abs(houses[i].second - stores[j].second);
		}
	}

	vector<int> temp;
	bf(0, stores.size(), m, temp, houses, stores, costs);
	cout << ans;

	return 0;
}