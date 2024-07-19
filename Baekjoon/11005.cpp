#include <string>
#include <iostream>

using namespace std;

string itos(int i)
{
	if (i < 10)
		return to_string(i);
	else
	{
		string str(1, i - 10 + 'A');
		return str;
	}
}

int main()
{
	int n, b;
	cin >> n >> b;
	string answer = "";
	while (n != 0)
	{
		answer = itos(n % b) + answer;
		n = n / b;
	}
	cout << answer;
	return 0;
}