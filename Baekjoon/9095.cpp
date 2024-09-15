#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int s = 0; s < t; ++s)
	{
		int n;
		cin >> n;

		// factorial
		int n_fac = 1;
		vector<int> fac(n + 1);
		fac[0] = 1;
		fac[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			n_fac *= i;
			fac[i] = n_fac;
		}

		set<vector<int>> sets;
		for (int i = 0; i * 3 <= n; ++i)
		{
			for (int j = 0; i * 3 + j * 2 <= n; ++j)
			{
				sets.insert({ n - 3 * i - 2 * j,j,i });
			}
		}

		int sum = 0;
		for (auto iter : sets)
		{
			sum += fac[iter[0] + iter[1] + iter[2]] / (fac[iter[0]] * fac[iter[1]] * fac[iter[2]]);
		}

		cout << sum << '\n';
	}
	return 0;
}