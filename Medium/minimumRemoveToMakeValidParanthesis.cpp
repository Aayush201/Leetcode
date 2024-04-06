/*
Problem Link : https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/?envType=daily-question&envId=2024-04-06
*/

class Solution
{
public:
    // O(n) time and O(n) space
    string approach1(string &s)
    {
        stack<pair<char, int>> st;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(' || s[i] == ')')
            {
                if (st.empty())
                {
                    st.push({s[i], i});
                }
                else
                {
                    if (st.top().first == '(' && s[i] == ')')
                        st.pop();
                    else
                        st.push({s[i], i});
                }
            }
        }
        unordered_map<int, int> mp;
        while (!st.empty())
        {
            mp[st.top().second]++;
            st.pop();
        }
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (mp[i])
                continue;
            else
                ans += s[i];
        }
        return ans;
    }

    // Using O(N)time and O(N) space (Without using the visited map)
    string approach2(string &s)
    {
        stack<char> st;
        int open = 0, close = 0;
        for (auto &x : s)
        {
            if (x == '(')
            {
                open++;
                st.push('(');
                continue;
            }
            if (x == ')')
            {
                if (st.empty())
                    x = '*';
                else
                {
                    if (st.top() == '(')
                    {
                        st.pop();
                        open--;
                    }
                    else
                    {
                        x = '*';
                    }
                }
            }
        }
        int n = s.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                s[i] = '*';
                open--;
            }
            if (open == 0)
                break;
        }
        string ans = "";
        for (auto x : s)
        {
            if (x != '*')
                ans += x;
        }
        return ans;
    }

    // In O(N) time and O(1) space
    string approach3(string &s)
    {
        int open = 0, close = 0;
        string ans = "";
        for (auto &x : s)
        {
            if (x == '(')
            {
                open++;
                continue;
            }
            if (x == ')')
            {
                if (open > 0)
                    open--;
                else
                {
                    x = '*';
                }
            }
        }
        int n = s.length();
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(')
            {
                if (open <= 0)
                    ans += s[i];
                else
                    open--;
                continue;
            }
            if (s[i] == ')' || s[i] != '*')
                ans += s[i];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    string minRemoveToMakeValid(string s)
    {
        // return approach1(s);
        // return approach2(s);
        return approach3(s);
    }
};