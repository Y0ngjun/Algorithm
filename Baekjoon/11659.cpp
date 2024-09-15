#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<int> nums(n + 1);
	nums[0] = 0;
	for (int i = 1; i < n + 1; ++i)
	{
		cin >> nums[i];
		nums[i] += nums[i - 1];
	}


	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		cout << nums[b] - nums[a - 1] << '\n';;
	}

	return 0;
}