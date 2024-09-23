#include <iostream>
#include <string>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string binary;
	cin >> binary;

	string oct = "";
	int strSize = binary.size();
	if (strSize % 3 == 1)
		oct = binary[0];
	else if (strSize % 3 == 2)
		oct = char((binary[0] - '0') * 2 + binary[1]) + oct;

	for (int i = strSize % 3 + 0; i != strSize; i += 3)
	{
		oct += char((binary[i] - '0') * 4 + (binary[i + 1] - '0') * 2 + binary[i + 2]);
	}

	cout << oct;
	return 0;
}