#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<bool>> paper(n, vector<bool>(n, false));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			bool color;
			cin >> color;
			paper[i][j] = color;
		}
	}

	int count0 = 0, count1 = 0;
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0},n });
	while (!q.empty())
	{
		int y = q.front().first.first;
		int x = q.front().first.second;
		int n = q.front().second;
		q.pop();

		bool color = paper[y][x];
		bool flag = true;
		for (int i = y; i < y + n; ++i)
		{
			for (int j = x; j < x + n; ++j)
			{
				if (color != paper[i][j])
				{
					flag = false;
					break;
				}
			}
			if (!flag)
				break;
		}
		if (!flag)
		{
			q.push({ {y, x}, n / 2 });
			q.push({ {y, x + n / 2}, n / 2 });
			q.push({ {y + n / 2, x + n / 2}, n / 2 });
			q.push({ {y + n / 2, x } , n / 2 });
		}
		else
		{
			if (color)
				++count1;
			else
				++count0;
		}
	}

	cout << count0 << '\n' << count1;

	return 0;
}