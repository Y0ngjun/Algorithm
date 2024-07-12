#include <iostream>
#include <string>

using namespace std;

int main() {
	int count = 0;
	string str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		bool sign = true;
		bool alphabet[26]{};
		for (int j = 1; j < str.size(); j++) {
			if (str[j] != str[j - 1]) {
				if (alphabet[str[j] - 'a']) {
					sign = false;
					break;
				}
				alphabet[str[j - 1] - 'a'] = true;
			}
		}
		if (sign)
			count++;
	}
	cout << count;
	return 0;
}