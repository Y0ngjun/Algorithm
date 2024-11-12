#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;

	int n = a.size();
	int m = b.size();

	vector<vector<int>> edit(n + 1, vector<int>(m + 1));
	for (int i = 1; i <= n; ++i)
		edit[i][0] = i;
	for (int i = 1; i <= m; ++i)
		edit[0][i] = i;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			edit[i][j] = min({ edit[i - 1][j] + 1, edit[i][j - 1] + 1,
				(a[i - 1] == b[j - 1] ? edit[i - 1][j - 1] : edit[i - 1][j - 1] + 1) });
		}
	}

	cout << edit[n][m];

	return 0;
}