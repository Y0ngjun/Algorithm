#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> questk;
	vector<int> isStack(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> isStack[i];
	}

	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (!isStack[i])
			questk.push_back(num);
	}

	queue<int> que;

	for (auto iter = questk.rbegin(); iter != questk.rend(); ++iter)
		que.push(*iter);

	int m;
	cin >> m;

	for (int i = 0; i < m; ++i)
	{
		int num;
		cin >> num;
		que.push(num);
		cout << que.front() << ' ';
		que.pop();
	}

	return 0;
}