#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s[5];
	cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4];
	int j = 0;
	while (true)
	{
		string temp = "";
		for (int i = 0; i < 5; i++)
		{
			if (j < s[i].size())
				temp += s[i][j];
		}
		j++;
		if (temp != "")
			cout << temp;
		else
			break;
	}
	return 0;
}