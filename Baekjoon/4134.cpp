#include <iostream>

using namespace std;

bool isPrime(unsigned int num)
{
	if (num < 2)
		return false;
	bool flag = false;
	int i = 2;
	while (i * i <= num)
	{
		if (num % i++ == 0)
			flag = true;
	}
	if (flag)
		return false;
	return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		unsigned int num;
		cin >> num;

		unsigned int answer = 0;
		while (answer == 0)
		{
			if (isPrime(num++))
				answer = num - 1;
		}

		cout << answer << '\n';
	}

	return 0;
}