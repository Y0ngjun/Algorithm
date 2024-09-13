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

	vector<int> arr = { 0, 0 };

	while (arr.size() <= n)
	{
		int num = arr.size();
		vector<int> dp;
		if (num % 3 == 0)
			dp.push_back(1 + arr[num / 3]);
		if (num % 2 == 0)
			dp.push_back(1 + arr[num / 2]);
		dp.push_back(1 + arr[num - 1]);
		arr.push_back(*min_element(dp.begin(), dp.end()));
	}

	cout << arr.back();

	return 0;
}