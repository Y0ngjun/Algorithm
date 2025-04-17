#include <iostream>
#include <vector>

using namespace std;

int cal_time(int w, const vector<vector<int>>& before, const vector<int>& time, vector<int>& total_time)
{
	if (before[w].size() == 0)
		return time[w];

	if (total_time[w] != -1)
		return total_time[w];

	int max_b = 0;
	for (int b : before[w])
		max_b = max(max_b, cal_time(b, before, time, total_time));

	total_time[w] = max_b + time[w];
	return total_time[w];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;

		vector<int> time(n + 1);			// 편의상 1-index 사용
		for (int i = 1; i <= n; ++i)
			cin >> time[i];

		vector<vector<int>> before(n + 1);	// 편의상 1-index 사용
		for (int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> x >> y;
			before[y].push_back(x);			// y를 짓기 위해서는 x를 먼저 지어야 함.
		}

		int w;
		cin >> w;

		vector<int> total_time(n + 1, -1);
		cout << cal_time(w, before, time, total_time) << '\n';
	}

	return 0;
}