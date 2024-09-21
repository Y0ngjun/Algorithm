#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int n, m;
		cin >> n >> m;

		vector<int> up(m);
		for (int j = 0; j < m; ++j)
			up[j] = j + 1;

		vector<int> down(m);
		for (int j = 0; j < n; ++j)
			down[j] = j + 1;
		for (int j = n; j < m; ++j)
			down[j] = j - n + 1;

		for (int j = 0; j < m; ++j)
		{
			for (int k = 0; k < m; ++k)
			{
				int GCD = gcd(up[j], down[k]);
				up[j] /= GCD;
				down[k] /= GCD;
			}
		}

		long long result = accumulate(up.begin(), up.end(), 1, multiplies<long long>());

		cout << result << '\n';
	}

	return 0;
}