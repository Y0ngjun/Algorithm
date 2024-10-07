#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, b;
	cin >> n >> m >> b;

	int min = 256, max = 0;
	vector<vector<int>> ground(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> ground[i][j];
			min = ground[i][j] < min ? ground[i][j] : min;
			max = ground[i][j] > max ? ground[i][j] : max;
		}
	}

	int T = 210000000, H = 0;
	for (int i = min; i <= max; ++i)
	{
		int inven = b;
		int time = 0;
		for (int y = 0; y < n; ++y)
		{
			for (int x = 0; x < m; ++x)
			{
				int work = ground[y][x] - i;
				inven += work;
				if (work < 0)
					time -= work;
				else
					time += 2 * work;
			}
		}
		if (inven >= 0)
		{
			if (time <= T)
			{
				T = time;
				H = i;
			}
		}
	}
	cout << T << ' ' << H;

	return 0;
}