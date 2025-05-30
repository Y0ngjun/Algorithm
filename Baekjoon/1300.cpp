#include <iostream>

using namespace std;

int n, k;

pair<int, int> bound(int m)
{
	int lb = 0, ub = 0;
	int limit = min(n, m);

	for (int i = 1; i <= limit; ++i)
	{
		lb += min(n, (m - 1) / i);
		ub += min(n, m / i);
	}

	return { lb + 1, ub + 1 };
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	int left = 1, right = k;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		pair<int, int> temp = bound(middle);
		int lb = temp.first, ub = temp.second;

		if (k < lb)
		{
			right = middle - 1;
		}
		else if (k >= ub)
		{
			left = middle + 1;
		}
		else
		{
			cout << middle;
			break;
		}
	}

	return 0;
}