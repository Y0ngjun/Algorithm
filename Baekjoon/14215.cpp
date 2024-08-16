#include <algorithm>

#include <iostream>

using namespace std;

int main()
{
	int abc[3];
	for (int& i : abc)
		cin >> i;
	std::sort(abc, abc + 3);
	if (abc[0] + abc[1] > abc[2])
		cout << abc[0] + abc[1] + abc[2];
	else
		cout << 2 * (abc[0] + abc[1]) - 1;
	return 0;
}