#include <iostream>

using namespace std;

int main()
{
	int max = -1;
	int count = 0;
	int idx;
	for (int i = 0; i < 81; i++)
	{
		count++;
		int temp;
		cin >> temp;
		if (temp > max)
		{
			max = temp;
			idx = count;
		}
	}
	cout << max << endl << (idx - 1) / 9 + 1 << ' ' << (idx - 1) % 9 + 1;
	return 0;
}