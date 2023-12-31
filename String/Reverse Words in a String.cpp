// Brute

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s = "TUF is great for interview preparation";
    cout << "Before reversing words: " << endl;
    cout << s << endl;
    s += " ";
    stack<string> st;
    int i;
    string str = "";
    for (i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            st.push(str);
            str = "";
        }
        else
            str += s[i];
    }
    string ans = "";
    while (st.size() != 1)
    {
        ans += st.top() + " ";
        st.pop();
    }
    ans += st.top(); // The last word should'nt have a space after it
    cout << "After reversing words: " << endl;
    cout << ans;
    return 0;
}

// Optimal

class Solution
{
public:
    string reverseWords(string s)
    {
        string ans = "";
        int n = s.size();
        int index = 0;

        while (index < n)
        {
            if (s[index] == ' ')
            {
                while (index < n && s[index] == ' ')
                {
                    index++;
                }
            }
            else
            {
                string temp = "";
                while (index < n && s[index] != ' ')
                {
                    temp += s[index++];
                }
                if (!ans.empty())
                {
                    ans = " " + ans; // Add space if ans is not empty
                }
                ans = temp + ans;
            }
        }

        return ans;
    }
};
