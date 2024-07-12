#include <iostream>
#include <string>

using namespace std;

int main() {
	bool answer = true;
	string str;
	cin >> str;
	for (int i = 0; i < (str.size() / 2); i++) {
		if (str[i] != str[str.size() - 1 - i]) {
			answer = false;
			break;
		}
	}
	cout << answer;
	return 0;
}