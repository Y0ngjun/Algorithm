#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 0;i < t; ++i)
	{
		int n;
		cin >> n;

		if (n == 0)
		{
			cout << 1 << ' ' << 0 << '\n';
			continue;
		}
		if (n == 1)
		{
			cout << 0 << ' ' << 1 << '\n';
			continue;
		}
		
		int a0 = 1, a1 = 0; // 0
		int b0 = 0, b1 = 1; // 1
		for (int j = 2; j <= n; ++j)
		{
			int tempA = a1;
			a1 += a0;
			a0 = tempA;

			int tempB = b1;
			b1 += b0;
			b0 = tempB;
		}
		cout << a1 << ' ' << b1 << '\n';
	}

	return 0;
}