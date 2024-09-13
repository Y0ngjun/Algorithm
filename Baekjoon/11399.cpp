#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> time(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> time[i];
	}

	sort(time.begin(), time.end(), [](auto a, auto b)
		{
			return a > b;
		});

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += time[i] * (i + 1);
	}

	cout << sum;

	return 0;
}