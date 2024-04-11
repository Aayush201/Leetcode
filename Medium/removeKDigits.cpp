/*
Problem Link : https://leetcode.com/problems/remove-k-digits/description/
*/

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        string ans = "";
        ans += num[0];
        int n = num.length();
        if (k == n)
            return "0";
        for (int i = 1; i < n; i++)
        {
            if (k > 0)
            {
                if (ans != "")
                {
                    if (ans.back() > num[i])
                    {
                        ans.pop_back();
                        k--;
                    }
                    if (ans == "" && num[i] == 0)
                        continue;
                    else
                        ans += num[i];
                }
                cout << ans << endl;
            }
            else
                ans += num[i];
        }

        while (ans[0] == '0')
            ans.erase(ans.begin());
        if (ans == "")
            ans = "0";
        return ans;
    }
};