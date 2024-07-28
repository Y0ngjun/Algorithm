#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int sum = 0;
	int i = 0;
	int up, down;
	while (sum < n)
	{
		sum += ++i;
	}
	if (i % 2)
	{
		up = i;
		down = 1;
		for (int j = 0; j < i - (sum - n) - 1; j++)
		{
			--up;
			++down;
		}
	}
	else
	{
		up = 1;
		down = i;
		for (int j = 0; j < i - (sum - n) - 1; j++)
		{
			++up;
			--down;
		}
	}

	cout << up << '/' << down;

	return 0;
}