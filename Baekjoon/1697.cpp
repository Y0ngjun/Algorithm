#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	if (n >= k)
	{
		cout << n - k;
		return 0;
	}

	vector<int> dp(100001, -1);
	dp[k] = 0;

	queue<int> bfs;
	bfs.push(k);
	while (!bfs.empty())
	{
		int idx = bfs.front();
		bfs.pop();
		int value = dp[idx];

		if (idx - 1 >= 0 && dp[idx - 1] == -1)
		{
			dp[idx - 1] = value + 1;
			if (idx - 1 == n)
				break;
			bfs.push(idx - 1);
		}
		if (idx % 2 == 0 && idx / 2 <= 100000 && dp[idx / 2] == -1)
		{
			dp[idx / 2] = value + 1;
			if (idx / 2 == n)
				break;
			bfs.push(idx / 2);
		}
		if (idx + 1 <= 100000 && dp[idx + 1] == -1)
		{
			dp[idx + 1] = value + 1;
			if (idx + 1 == n)
				break;
			bfs.push(idx + 1);
		}
	}

	cout << dp[n];
	return 0;
}