#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '=') {
			if (str[i - 1] == 'c' || str[i - 1] == 's') {
				continue;
			}
			else if (str[i - 1] == 'z') {
				if (str[i - 2] == 'd') {
					count--;
				}
				continue;
			}
		}
		else if (str[i] == '-')
			continue;
		else if (str[i] == 'j') {
			if (str[i - 1] == 'l' || str[i - 1] == 'n') {
				continue;
			}
		}
		count++;
	}
	cout << count << endl;
	return 0;
}