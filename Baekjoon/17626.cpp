#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<char> dp(n + 1, 4);
	for (int i = 1; i * i <= n; ++i)
	{
		dp[i * i] = 1;

		for (int j = 1; i * i + j * j <= n; ++j)
		{
			int temp = i * i + j * j;
			dp[temp] = dp[temp] < 2 ? dp[temp] : 2;

			for (int k = 1; i * i + j * j + k * k <= n; ++k)
			{
				int temp = i * i + j * j + k * k;
				dp[temp] = dp[temp] < 3 ? dp[temp] : 3;
			}
		}
	}

	cout << static_cast<int>(dp[n]);

	return 0;
}