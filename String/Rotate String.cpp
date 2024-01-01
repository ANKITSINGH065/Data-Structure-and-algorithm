

// Brute Force

/*
Cutt the first character and push in back and compary

ex:-  s = "abcde" ,goal = "cdeab"

         "bcdea"            "cdeab"
         "cdeab"            "cdeab" ("Eqal")


*/

class Solution
{
public:
    bool rotateString(string s, string t)
    {

        int n = s.size();
        if (s.size() != t.size())
        {
            return false;
        }
        if (s == t)
        {
            return true;
        }
        for (int i = 0; i < n; i++)
        {

            char tt = s[0];
            string p = s.substr(1, n);
            p.push_back(tt);
            s = p;
            if (s == t)
            {
                return true;
            }
        }
        return false;
    }
};

// Optimal  using KMP (Knuth-Morris-Pratt) Algorithm

class Solution
{
public:
    bool rotateString(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        if (n > m || m > n)
            return false;

        string KMP = s + s;

        int found = KMP.find(t);
        if (found == -1)
        {
            return false;
        }
        return true;
    }
};
