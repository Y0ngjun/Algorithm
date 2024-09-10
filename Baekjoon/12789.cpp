#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; ++i)
		cin >> vec[i];

	stack<int> line;
	for (int i = 0; i < n; ++i)
		line.push(vec[n - 1 - i]);

	stack<int> load;
	int count = 1;

	bool flag = true;
	while (!line.empty() || !load.empty())
	{
		if (!line.empty())
		{
			if (line.top() == count)
			{
				line.pop();
				count++;
			}
			else
			{
				if (!load.empty())
				{
					if (load.top() == count)
					{
						load.pop();
						count++;
					}
					else
					{
						load.push(line.top());
						line.pop();
					}
				}
				else
				{
					load.push(line.top());
					line.pop();
				}
			}
		}
		else
		{
			if (!load.empty())
			{
				if (load.top() == count)
				{
					load.pop();
					count++;
				}
				else
				{
					flag = false;
					break;
				}
			}
		}
	}

	if (flag)
		cout << "Nice";
	else
		cout << "Sad";

	return 0;
}