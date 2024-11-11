#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<char, char>> nodes(n); // idx = node - 'A'
	for (int i = 0; i < n; ++i)
	{
		char node;
		cin >> node;
		cin >> nodes[node - 'A'].first >> nodes[node - 'A'].second;
	}

	{
		// VLR
		stack<char> VLR;
		VLR.push('A');
		vector<bool> visited(n);
		while (!VLR.empty())
		{
			char curr = VLR.top();
			VLR.pop();
			char left = nodes[curr - 'A'].first;
			char right = nodes[curr - 'A'].second;
			cout << curr;
			if (right != '.')
				VLR.push(right);
			if (left != '.')
				VLR.push(left);
		}
		cout << '\n';
	}

	{
		// LVR
		stack<char> LVR;
		LVR.push('A');
		vector<bool> visited(n);
		while (!LVR.empty())
		{
			char curr = LVR.top();
			LVR.pop();
			char left = nodes[curr - 'A'].first;
			char right = nodes[curr - 'A'].second;
			if (left == '.' || visited[left - 'A'])
			{
				cout << curr;
				visited[curr - 'A'] = true;
				if (right != '.')
					LVR.push(right);
			}
			else
			{
				LVR.push(curr);
				LVR.push(left);
			}
		}
		cout << '\n';
	}

	{
		// LRV
		stack<char> LRV;
		LRV.push('A');
		vector<bool> visited(n);
		while (!LRV.empty())
		{
			char curr = LRV.top();
			LRV.pop();
			char left = nodes[curr - 'A'].first;
			char right = nodes[curr - 'A'].second;
			if ((left == '.' || visited[left - 'A']) && (right == '.' || visited[right - 'A']))
			{
				cout << curr;
				visited[curr - 'A'] = true;
			}
			else
			{
				LRV.push(curr);
				if (right != '.' && !visited[right - 'A'])
					LRV.push(right);
				if (left != '.' && !visited[left - 'A'])
					LRV.push(left);
			}
		}
	}
	return 0;
}