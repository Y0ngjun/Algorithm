#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> solutions(n);
	for (int i = 0; i < n; ++i)
		cin >> solutions[i];

	int ans_left, ans_right, ans = 2000000000;
	int left = 0, right = n - 1;
	while (left < right)
	{
		int temp = solutions[left] + solutions[right];
		if (abs(ans) > abs(temp))
		{
			ans = temp;
			ans_left = left;
			ans_right = right;
		}
		if (temp > 0)
			right--;
		else if (temp < 0)
			left++;
		else
			break;
	}

	cout << solutions[ans_left] << ' ' << solutions[ans_right];

	return 0;
}