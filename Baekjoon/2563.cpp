#include <iostream>

using namespace std;

int main()
{
	bool paper[100][100]{};
	int paperNum;
	cin >> paperNum;
	for (int i = 0; i < paperNum; i++)
	{
		int x, y;
		cin >> x >> y;
		for (int j = x; j < x + 10; j++)
		{
			for (int k = y; k < y + 10; k++)
				paper[j][k] = true;
		}
	}
	int count = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (paper[i][j] == true)
				count++;
		}
	}
	cout << count;
	return 0;
}