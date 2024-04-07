/*
Problem Link : https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
*/
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int ans = 0;
        stack<char> st;
        for (auto x : s)
        {
            if (x == '(')
            {
                st.push(x);
            }
            else
            {
                if (st.empty())
                    ans++;
                else if (st.top() == '(')
                    st.pop();
                else
                    st.push(x);
            }
        }
        ans += st.size();
        return ans;
    }
};