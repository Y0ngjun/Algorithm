// BOJ 17276 배열 돌리기
#include <utility>
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

int in[499][499];
int temp[8][249];

// dy[i] = {출발점 / ((n-1)/2), 변화량}, 각 직선을 표현
pair<int, int> dy[8] = { {0, 1}, {0, 1}, {0, 1}, {1, 0}, {2, -1}, {2, -1}, {2, -1}, {1, 0} };
pair<int, int> dx[8] = { {0, 1}, {1, 0}, {2, -1}, {2, -1}, {2, -1}, {1, 0}, {0, 1}, {0, 1} };

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        // d = 0(-360, 360), 45(-315), 90(-270), 135(-225), 180(-180), 225(-135), 270(-90), 315(-45)
        int n, d;
        cin >> n >> d;

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> in[i][j];
            }
        }

        // 변화각을 dir로 변환
        // dir = ((d + 360) % 360) / 45, 0 <= dir < 8
        int dir = ((d + 360) % 360) / 45;

        // 회전해 오는 값 구하기
        for (int i = 0; i < 8; ++i)
        {
            int j1 = (n - 1) / 2;
            int dy2 = dy[(i + 8 - dir) % 8].second;
            int dx2 = dx[(i + 8 - dir) % 8].second;
            for (int j = 0,
                y2 = dy[(i + 8 - dir) % 8].first * (n - 1) / 2,
                x2 = dx[(i + 8 - dir) % 8].first * (n - 1) / 2;
                j < j1;
                j += 1,
                y2 += dy2,
                x2 += dx2)
            {
                temp[i][j] = in[y2][x2];
            }
        }

        // 배열을 업데이트
        for (int i = 0; i < 8; ++i)
        {
            int j1 = (n - 1) / 2;
            int dy1 = dy[i].second;
            int dx1 = dx[i].second;
            for (int j = 0,
                y1 = dy[i].first * (n - 1) / 2,
                x1 = dx[i].first * (n - 1) / 2;
                j < j1;
                j += 1,
                y1 += dy1,
                x1 += dx1)
            {
                in[y1][x1] = temp[i][j];
            }
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cout << in[i][j] << ' ';
            }

            cout << '\n';
        }
    }

    return 0;
}
