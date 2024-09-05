#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a1, a2, b1, b2;
	cin >> a1 >> b1 >> a2 >> b2;

	int a = a1 * b2 + a2 * b1;
	int b = b1 * b2;

	while (true)
	{
		int i = 1;
		bool flag = false;
		while (true)
		{
			++i;
			if (a % i == 0 && b % i == 0)
			{
				a /= i;
				b /= i;
				break;
			}
			if (i > a || i > b)
			{
				flag = true;
				break;
			}
		}
		if (flag)
			break;
	}

	cout << a << ' ' << b;

	return 0;
}