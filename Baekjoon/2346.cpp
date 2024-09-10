#include <iostream>
#include <deque>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	deque<pair<int, int>> dq;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		dq.push_back({ i + 1, num });
	}

	while (!dq.empty())
	{
		cout << dq.front().first << ' ';
		int go = dq.front().second;
		dq.pop_front();
		if (dq.empty())
			break;
		if (go > 0)
		{
			for (int i = 0; i < go - 1; ++i)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else
		{
			for (int i = 0; i < -go; ++i)
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}

	return 0;
}