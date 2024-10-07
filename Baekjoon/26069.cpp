#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	unordered_set<string> dance;
	dance.insert("ChongChong");
	for (int i = 0; i < n; ++i)
	{
		string a, b;
		cin >> a >> b;
		if (dance.find(a) != dance.end() || dance.find(b) != dance.end())
		{
			dance.insert(a);
			dance.insert(b);
		}
	}
	cout << dance.size();

	return 0;
}