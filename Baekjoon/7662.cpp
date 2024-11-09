#include <iostream>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--)
	{
		multiset<int> q;
		int k;
		cin >> k;
		while (k--)
		{
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I')
			{
				q.insert(n);
			}
			else
			{
				if (!q.empty())
				{
					if (n == 1)
					{
						q.erase(--q.end());
					}
					else
					{
						q.erase(q.begin());
					}
				}
			}
		}

		if (q.empty())
			cout << "EMPTY\n";
		else
			cout << *--q.end() << ' ' << *q.begin() << '\n';
	}

	return 0;
}