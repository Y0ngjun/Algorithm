#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int bag = -1;
	for (int i = 0; i <= n / 5; ++i) // 5kg ������ 0������ n/5�� ���� ����
	{
		int sugar = n;
		int count = 0;

		sugar -= i * 5; // ������ 5kg * ������ ��ŭ ����
		count += i; // ���� ī��Ʈ�� 5kg������ŭ ����
		if (sugar % 3 == 0) // ���� ������ 3���� ������ �������ٸ�
		{
			count += (sugar / 3); // ����ī��Ʈ�� 3kg������ŭ ����
			bag = count; // count�� ���� �پ�� �������� �񱳰� ���ʿ�
		}
	}
	cout << bag;
	return 0;
}