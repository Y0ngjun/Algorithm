#include <iostream>

using namespace std;

bool isSpecial(int n)
{
	for (int i = 2; i < n; ++i)
	{
		if (!(n % i))
			return false;
	}
	if (n == 1)
		return false;
	return true;
}

int main()
{
	int m, n, sum = 0, first;
	cin >> m >> n;
	for (int i = m; i <= n; ++i)
	{
		if (isSpecial(i))
		{
			if (!sum)
				first = i;
			sum += i;
		}
	}
	if (sum)
		cout << sum << endl << first;
	else
		cout << -1;
	return 0;
}