#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	vector<bool> isPrime(1000000, true);

	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i * i <= 1000000; ++i)
	{
		if (isPrime[i])
		{
			for (int j = i * i; j < 1000000; j += i)
				isPrime[j] = false;
		}
	}

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;

		if (n == 4)
		{
			cout << 1 << '\n';
			continue;
		}

		int count = 0;
		for (int j = 3; j <= n / 2; j += 2)
		{
			if (isPrime[j])
				if (isPrime[n - j])
					count++;
		}
		cout << count << '\n';
	}

	return 0;
}