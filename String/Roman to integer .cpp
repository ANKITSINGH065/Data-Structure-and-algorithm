// Optimal
class Solution
{
public:
    int romanToInt(string s)
    {
        int n = s.size();
        unordered_map<string, int> mp;
        mp["I"] = 1;
        mp["V"] = 5;
        mp["X"] = 10;
        mp["L"] = 50;
        mp["C"] = 100;
        mp["D"] = 500;
        mp["M"] = 1000;
        mp["IV"] = 4;   // Instead of "IV"
        mp["IX"] = 9;   // Instead of "IX"
        mp["XL"] = 40;  // Instead of "XL"
        mp["XC"] = 90;  // Instead of "XC"
        mp["CD"] = 400; // Instead of "CD"
        mp["CM"] = 900; // Instead of "CM"

        if (n == 1)
        {
            return mp[s];
        }

        int ans = 0;

        for (int index = 0; index < n;)
        {

            if (index + 1 < n && mp[s.substr(index, 2)] != 0)
            {
                cout << "outside" << endl;
                ans += mp[s.substr(index, 2)];
                index += 2;
            }
            else
            {
                cout << "inside" << endl;
                ans += mp[s.substr(index, 1)];
                index++;
            }
        }

        return ans;
    }
};
