#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

void simulation(int& ans, int w, int t, int k, int f, int x, vector<int> fire)
{
	vector<int> temp = fire;
	for (int i = 0; i < fire.size(); ++i)
	{
		if (fire[i] != 0 && i != x)
		{
			int minus = 3;
			for (int j = i - 1; j <= i + 1; j += 2)
			{
				if (0 <= j && j < fire.size() && fire[j] != 0)
				{
					minus -= 1;
				}
			}
			temp[i] = fire[i] - minus;
			if (temp[i] <= 0)
			{
				f -= 1;
				temp[i] = 0;
			}
		}
	}

	if (f < k)
		return;

	if (t == 1)
	{
		if (f >= k)
			ans += 1;
	}
	else
	{
		for (int i = w - 1; i <= w + 1; ++i)
		{
			if (i < 0 || i >= fire.size())
				continue;

			simulation(ans, i, t - 1, k, f, i, temp);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, w, t, k, f = 0, ans = 0;
	cin >> n >> w >> t >> k;

	vector<int> fire(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> fire[i];
		if (fire[i] > 0)
			f += 1;
	}

	simulation(ans, w, t, k, f, -1, fire);

	cout << ans;

	return 0;
}