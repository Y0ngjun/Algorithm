#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int count = 0;
	set<string> hello;
	for (int i = 0; i < n; ++i)
	{
		string str;
		cin >> str;
		if (str == "ENTER")
			hello.clear();
		else
		{
			if (hello.find(str) == hello.end())
			{
				hello.insert(str);
				count++;
			}
		}
	}
	cout << count;
	return 0;
}