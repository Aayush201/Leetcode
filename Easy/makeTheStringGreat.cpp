/*Problem link : 
https://leetcode.com/problems/make-the-string-great/description/?envType=daily-question&envId=2024-04-05 
*/

class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;
        int n = s.length();
        st.push(s[0]);
        for (int i = 1; i < n; i++)
        {
            if (st.empty())
            {
                st.push(s[i]);
            }
            else
            {
                char ch = st.top();
                if (abs(ch - s[i]) == 32)
                {
                    st.pop();
                }
                else
                {
                    st.push(s[i]);
                }
            }
        }
        string ans = "";
        while (!st.empty())
        {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};