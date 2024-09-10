#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	stack<int> stk;

	for (int i = 0; i < n; ++i)
	{
		int cmd;
		cin >> cmd;
		switch (cmd)
		{
		case 1:
			int num;
			cin >> num;
			stk.push(num);
			break;
		case 2:
			if (stk.empty())
				cout << -1 << '\n';
			else
			{
				cout << stk.top() << '\n';
				stk.pop();
			}
			break;
		case 3:
			cout << stk.size() << '\n';
			break;
		case 4:
			if (stk.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
			break;
		case 5:
			if (stk.empty())
				cout << -1 << '\n';
			else
				cout << stk.top() << '\n';
			break;
		}
	}

	return 0;
}