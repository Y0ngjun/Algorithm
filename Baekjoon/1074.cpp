#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// 2^n * 2^n ĭ���� Z�ڷ� ��ȸ�� �� r��, c������ ���°�� �湮�ϴ°�.
	// ���� ���带 �»�� ���� ��ġ�� �� ���� ũ��(2^z)�� ��Ÿ����.
	// ī��Ʈ = 0���� �����Ѵ�.
	// n > 1 �� ��� n�� ��ġ�� �»��, ����, ���ϴ�, ���ϴ����� ������.
	// �� �� 0, (2^(n-1))^2, (2^(n-1))^2*2, (2^(n-1))^2*3 �� ī��Ʈ�� ���Ѵ�.
	// n�� 1�ΰ�� ī��Ʈ�� 1, 2, 3, 4�� ���Ѵ�.

	int n, r, c;
	cin >> n >> r >> c;

	int x = 0, y = 0, z = n, count = 0;
	while (z > 0)
	{
		int size = pow(2, z);
		int midX = x + size / 2;
		int midY = y + size / 2;
		if (z > 1)
		{
			if (c < midX)
			{
				// �»��
				if (r < midY)
				{

				}
				// ���ϴ�
				else
				{
					count += size * size / 2;
					y = midY;
				}
			}
			else
			{
				// ����
				if (r < midY)
				{
					count += size * size / 4;
					x = midX;
				}
				// ���ϴ�
				else
				{
					count += size * size / 4 * 3;
					x = midX;
					y = midY;
				}
			}
		}
		else if (z == 1)
		{
			if (c == x)
			{
				if (r != y)
					count += 2;
			}
			else
			{
				if (r == y)
					count += 1;
				else
					count += 3;
			}
		}
		--z;
	}
	cout << count;
	return 0;
}

