#include <iostream>

using namespace std;

bool isPrime(int n)
{
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	if (n % 2 == 0)
		return false;
	for (int i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	while (n)
	{
		int count = 0;
		for (int i = n + 1; i <= 2 * n; ++i)
		{
			if (isPrime(i))
				count++;
		}

		cout << count << '\n';

		cin >> n;
	}

	return 0;
}