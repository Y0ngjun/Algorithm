#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	priority_queue<int> pq;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (num)
			pq.push(num);
		else
		{
			if (pq.empty())
				cout << 0 << '\n';
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}