
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
#include <string>
#include <vector>
#include <stack>

using namespace std;

bool isComplete(string s, int start)
{
    stack<char> st;

    for (int j = start; j < start + s.size(); ++j)
    {
        int idx = j % s.size();
        if (s[idx] == '(' || s[idx] == '{' || s[idx] == '[')
            st.push(s[idx]);
        else if (s[idx] == ')')
        {
            if (st.empty() || st.top() != '(')
                return false;

            st.pop();
        }
        else if (s[idx] == '}')
        {
            if (st.empty() || st.top() != '{')
                return false;

            st.pop();
        }
        else if (s[idx] == ']')
        {
            if (st.empty() || st.top() != '[')
                return false;

            st.pop();
        }
    }

    return st.empty();
}

int solution(string s)
{
    int answer = 0;

    for (int i = 0; i < s.size(); ++i)
        if (isComplete(s, i))
            answer += 1;

    return answer;
}
