#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue<int> que;

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int num;
			cin >> num;
			que.push(num);
		}
		else if (cmd == "pop")
		{
			if (que.empty())
				cout << -1 << '\n';
			else
			{
				cout << que.front() << '\n';
				que.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << que.size() << '\n';
		}
		else if (cmd == "empty")
		{
			if (que.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cmd == "front")
		{
			if (que.empty())
				cout << -1 << '\n';
			else
				cout << que.front() << '\n';
		}
		else if (cmd == "back")
		{
			if (que.empty())
				cout << -1 << '\n';
			else
				cout << que.back() << '\n';
		}
	}

	return 0;
}