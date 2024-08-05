#include <iostream>

using namespace std;

int main()
{
	int n, k, c = 0, i = 1;
	cin >> n >> k;
	while (c != k)
	{
		if ((n % i) == 0)
		{
			c++;
		}
		if (i++ > n)
		{
			i = 1;
			break;
		}
	}
	cout << --i;
	return 0;
}