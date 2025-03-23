#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int limit = 1003002;

	vector<int> isPrime(limit, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 4; i < limit; i += 2)
		isPrime[i] = false;
	for (int i = 3; i < limit; ++i)
	{
		if (isPrime[i])
		{
			for (long long j = 1LL * i * i; j < limit; j += 2 * i)
			{
				isPrime[j] = false;
			}
		}
	}

	int n;
	cin >> n;

	for (int i = n; i < limit; ++i)
	{
		if (isPrime[i])
		{
			string s = to_string(i);
			bool isPal = true;
			for (int j = 0; j < s.size() / 2; ++j)
				if (s[j] != s[s.size() - 1 - j])
					isPal = false;

			if (isPal)
			{
				cout << i;
				return 0;
			}
		}
	}

	return 0;
}