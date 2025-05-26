#include <iostream>

using namespace std;

int hist[100000];

long long histogram(int start, int end)
{
	if (start + 1 == end)
		return hist[start];

	int mid = (start + end) / 2;
	long long ret = max(histogram(start, mid), histogram(mid, end));

	int left = mid - 1;
	int right = mid;
	int level = min(hist[left], hist[right]);
	while (true)
	{
		ret = max(ret, 1LL * level * (right - left + 1));

		if (left == start && right == end - 1)
			break;
		else if (left == start)
		{
			++right;
			level = min(level, hist[right]);
		}
		else if (right == end - 1)
		{
			--left;
			level = min(level, hist[left]);
		}
		else if (hist[left - 1] > hist[right + 1])
		{
			--left;
			level = min(level, hist[left]);
		}
		else
		{
			++right;
			level = min(level, hist[right]);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	while (true)
	{
		int n;
		cin >> n;

		if (n == 0)
			break;

		for (int i = 0; i < n; ++i)
			cin >> hist[i];

		cout << histogram(0, n) << '\n';
	}

	return 0;
}