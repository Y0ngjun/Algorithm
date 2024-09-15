#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;

		if (n < 4)
		{
			cout << 1 << '\n';
			continue;
		}
		if (n < 6)
		{
			cout << 2 << '\n';
			continue;
		}

		int idx = 3;
		int pre = 2;
		vector<long long> P = { 1,1,2,2,1 };
		for (int i = 6; i <= n; ++i)
		{
			P[(++idx) % 5] += P[(++pre) % 5];
		}

		cout << P[idx % 5] << '\n';

	}

	return 0;
}