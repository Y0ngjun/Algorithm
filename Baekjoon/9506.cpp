#include <queue>

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n != -1)
	{
		int sum = 0;
		queue<int> q;
		for (int i = 1; i < n; ++i)
		{
			if (!(n % i))
			{
				sum += i;
				q.push(i);
			}
		}
		if (sum == n)
		{
			cout << n << " = " << q.front(); q.pop();
			while (!q.empty())
			{
				cout << " + " << q.front(); q.pop();
			}
			cout << endl;
		}
		else
		{
			cout << n << " is NOT perfect." << endl;
		}
		cin >> n;
	}
	return 0;
}