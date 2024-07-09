#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;
	for (char c : s)
	{
		if ((c >= 'a') && (c <= 'z'))
		{
			cout << char(c + ('A' - 'a'));
		}
		else
		{
			cout << char(c - ('A' - 'a'));
		}
	}
	return 0;
}