#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;

	// 1 <= n <= 100,000
	// 2 <= m <= 100,000
	// 0 <= k <= n - 1

	vector<vector<vector<int>>> lines(m);
	int line_num = 0;
	for (int i = 0; i < n; ++i)
	{
		int d, h;
		cin >> d >> h;
		lines[(line_num++) % m].push_back({ d, h });
	}

	int ans_line = k % m;
	int ans_order = k / m;
	int ans = ans_order;
	int lowest = 0;

	for (int i = 1; i <= ans_order; ++i)
	{
		if (lines[ans_line][lowest][0] == lines[ans_line][i][0])
		{
			if (lines[ans_line][lowest][1] > lines[ans_line][i][1])
			{
				lowest = i;
			}
		}
		else if (lines[ans_line][lowest][0] > lines[ans_line][i][0])
		{
			lowest = i;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		if (i == ans_line)
			continue;

		for (const auto& v : lines[i])
		{
			if (lines[ans_line][lowest][0] == v[0])
			{
				if (lines[ans_line][lowest][1] == v[1])
				{
					if (i < ans_line)
					{
						ans += 1;
					}
					else
					{
						break;
					}
				}
				else if (lines[ans_line][lowest][1] < v[1])
				{
					ans += 1;
				}
				else
				{
					break;
				}
			}
			else if (lines[ans_line][lowest][0] < v[0])
			{
				ans += 1;
			}
			else
			{
				break;
			}
		}
	}

	cout << ans;

	return 0;
}