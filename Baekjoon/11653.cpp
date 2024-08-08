#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n != 1)
	{
		for (int i = 2; i <= n; ++i)
		{
			if (n % i)
				continue;
			else
			{
				n /= i;
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}