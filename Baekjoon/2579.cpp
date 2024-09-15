#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> stair(n + 1);
	stair[0] = 0;
	for (int i = 1; i < n + 1; ++i)
		cin >> stair[i];

	vector<pair<int, int>> max;
	// first = linked, second = unlinked
	max.push_back({ stair[1],stair[1] });
	max.push_back({ max[0].second + stair[2], stair[2] });
	for (int i = 3; i <= n; ++i)
	{
		max.push_back({ max[i - 2].second + stair[i], (max[i - 3].first > max[i - 3].second ? max[i - 3].first : max[i - 3].second) + stair[i] });
	}

	cout << (max[n - 1].first > max[n - 1].second ? max[n - 1].first : max[n - 1].second);

	return 0;
}