// Brute Force

class Solution
{
public:
    string removeOuterParentheses(string s)
    {

        stack<char> st;
        string ans = "";
        for (auto ch : s)
        {

            if (st.empty())
            {
                st.push(ch);
            }
            else if (ch == '(')
            {
                st.push('(');
                ans = ans + '(';
            }
            else if (st.size() == 1 && st.top() == '(' && ch == ')')
            {
                st.pop();
            }
            else
            {
                ans = ans + ch;
                st.pop();
            }
        }

        return ans;
    }
};

// Optimal

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string res;
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' && count == 0)
                count++;
            else if (s[i] == '(' && count >= 1)
            {
                res += s[i];
                count++;
            }
            else if (s[i] == ')' && count > 1)
            {
                res += s[i];
                count--;
            }
            else if (s[i] == ')' && count == 1)
                count--;
        }
        return res;
    }
};