// BOJ 2150 Strongly Connected Component
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstdio>
#include <string>
#include <type_traits>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////
/*
 * Author : jinhan814
 * Date : 2021-05-05
 * Source : https://blog.naver.com/jinhan814/222266396476
 * Description : FastIO implementation for cin, cout.
 */
constexpr int SZ = 1 << 20;

class INPUT {
private:
	char read_buf[SZ];
	int read_idx, next_idx;
	bool __END_FLAG__, __GETLINE_FLAG__;
public:
	explicit operator bool() { return !__END_FLAG__; }
	bool IsBlank(char c) { return c == ' ' || c == '\n'; }
	bool IsEnd(char c) { return c == '\0'; }
	char _ReadChar() {
		if (read_idx == next_idx) {
			next_idx = fread(read_buf, sizeof(char), SZ, stdin);
			if (next_idx == 0) return 0;
			read_idx = 0;
		}
		return read_buf[read_idx++];
	}
	char ReadChar() {
		char ret = _ReadChar();
		for (; IsBlank(ret); ret = _ReadChar());
		return ret;
	}
	template<typename T> T ReadInt() {
		T ret = 0; char cur = _ReadChar(); bool flag = 0;
		for (; IsBlank(cur); cur = _ReadChar());
		if (cur == '-') flag = 1, cur = _ReadChar();
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret = 10 * ret + (cur & 15);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return flag ? -ret : ret;
	}
	string ReadString() {
		string ret; char cur = _ReadChar();
		for (; IsBlank(cur); cur = _ReadChar());
		for (; !IsBlank(cur) && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (IsEnd(cur)) __END_FLAG__ = 1;
		return ret;
	}
	double ReadDouble() {
		string ret = ReadString();
		return stod(ret);
	}
	string getline() {
		string ret; char cur = _ReadChar();
		for (; cur != '\n' && !IsEnd(cur); cur = _ReadChar()) ret.push_back(cur);
		if (__GETLINE_FLAG__) __END_FLAG__ = 1;
		if (IsEnd(cur)) __GETLINE_FLAG__ = 1;
		return ret;
	}
	friend INPUT& getline(INPUT& in, string& s) { s = in.getline(); return in; }
} _in;

class OUTPUT {
private:
	char write_buf[SZ];
	int write_idx;
public:
	~OUTPUT() { Flush(); }
	explicit operator bool() { return 1; }
	void Flush() {
		fwrite(write_buf, sizeof(char), write_idx, stdout);
		write_idx = 0;
	}
	void WriteChar(char c) {
		if (write_idx == SZ) Flush();
		write_buf[write_idx++] = c;
	}
	template<typename T> int GetSize(T n) {
		int ret = 1;
		for (n = n >= 0 ? n : -n; n >= 10; n /= 10) ret++;
		return ret;
	}
	template<typename T> void WriteInt(T n) {
		int sz = GetSize(n);
		if (write_idx + sz >= SZ) Flush();
		if (n < 0) write_buf[write_idx++] = '-', n = -n;
		for (int i = sz; i-- > 0; n /= 10) write_buf[write_idx + i] = n % 10 | 48;
		write_idx += sz;
	}
	void WriteString(string s) { for (auto& c : s) WriteChar(c); }
	void WriteDouble(double d) { WriteString(to_string(d)); }
} _out;

/* operators */
INPUT& operator>> (INPUT& in, char& i) { i = in.ReadChar(); return in; }
INPUT& operator>> (INPUT& in, string& i) { i = in.ReadString(); return in; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
INPUT& operator>> (INPUT& in, T& i) {
	if constexpr (is_floating_point_v<T>) i = in.ReadDouble();
	else if constexpr (is_integral_v<T>) i = in.ReadInt<T>(); return in;
}

OUTPUT& operator<< (OUTPUT& out, char i) { out.WriteChar(i); return out; }
OUTPUT& operator<< (OUTPUT& out, string i) { out.WriteString(i); return out; }
template<typename T, typename std::enable_if_t<is_arithmetic_v<T>>* = nullptr>
OUTPUT& operator<< (OUTPUT& out, T i) {
	if constexpr (is_floating_point_v<T>) out.WriteDouble(i);
	else if constexpr (is_integral_v<T>) out.WriteInt<T>(i); return out;
}

/* macros */
#define fastio 1
#define cin _in
#define cout _out
#define istream INPUT
#define ostream OUTPUT
/////////////////////////////////////////////////////////////////////////////////////////////

void DFS1(const vector<vector<int>>& G, vector<int>& visited, int u, vector<int>& scc)
{
	if (visited[u] == 1)
	{
		return;
	}

	visited[u] = 1;

	for (int v : G[u])
	{
		if (!visited[v])
		{
			DFS1(G, visited, v, scc);
		}
	}

	scc.push_back(u);
}

void DFS2(const vector<vector<int>>& Gt, vector<int>& visited, int u, vector<int>& temp)
{
	if (visited[u] == 1)
	{
		return;
	}

	visited[u] = 1;
	temp.push_back(u);

	for (int v : Gt[u])
	{
		if (!visited[v])
		{
			DFS2(Gt, visited, v, temp);
		}
	}
}

int main()
{
	int V, E;
	cin >> V >> E;

	vector<vector<int>> G(V + 1);
	vector<vector<int>> Gt(V + 1);

	for (int i = 0; i < E; ++i)
	{
		int u, v;
		cin >> u >> v;

		G[u].push_back(v);
		Gt[v].push_back(u);
	}

	vector<int> visited(V + 1, 0);
	vector<int> scc;
	for (int u = 1; u <= V; ++u)
	{
		if (visited[u])
		{
			continue;
		}

		DFS1(G, visited, u, scc);
	}

	visited.assign(V + 1, 0);
	vector<vector<int>> SCC;
	while (!scc.empty())
	{
		int u = scc.back();
		scc.pop_back();

		if (visited[u] == 1)
		{
			continue;
		}

		vector<int> temp;
		DFS2(Gt, visited, u, temp);

		sort(temp.begin(), temp.end());
		SCC.push_back(temp);
	}

	sort(SCC.begin(), SCC.end(), [](const auto& a, const auto& b) {return a[0] < b[0]; });

	cout << SCC.size() << '\n';
	for (const auto& scc : SCC)
	{
		for (int i : scc)
		{
			cout << i << ' ';
		}

		cout << -1 << '\n';
	}

	return 0;
}