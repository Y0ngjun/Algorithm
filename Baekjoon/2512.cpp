#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cal(vector<int> budget, int limit)
{
	int sum = 0;
	for (int bud : budget)
	{
		if (bud > limit)
			sum += limit;
		else
			sum += bud;
	}

	return sum;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> budget(n);
	for (int i = 0; i < n; ++i)
		cin >> budget[i];

	int m;
	cin >> m;

	sort(budget.begin(), budget.end());

	int left = 0;
	int right = budget[n - 1];
	int result = 0;

	while (left <= right)
	{
		int mid = (left + right) / 2;
		int mon = cal(budget, mid);

		if (mon > m)
			right = mid - 1;
		else
		{
			result = mid;
			left = mid + 1;
		}
	}

	cout << result;

	return 0;
}