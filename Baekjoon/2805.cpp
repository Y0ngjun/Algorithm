#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long cut(const vector<long long>& trees, long long h)
{
	long long sum = 0;
	for (long long tree : trees)
		if (tree > h)
			sum += (tree - h);
	return sum;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	long long n, m;
	cin >> n >> m;

	vector <long long> trees(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> trees[i];
	}

	sort(trees.begin(), trees.end());

	long long left = 0;
	long long right = trees[n - 1];
	long long result = 0;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long wood = cut(trees, mid);
		if (wood < m)
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