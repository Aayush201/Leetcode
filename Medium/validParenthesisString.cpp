/*
Problem Link : https://leetcode.com/problems/valid-parenthesis-string/description/?envType=daily-question&envId=2024-04-07
*/

class Solution
{
public:
    int usingDP(string &s, int index, int n, int openBracketCount, vector<vector<int>> &dp)
    {
        if (index == n)
            return openBracketCount == 0;
        if (dp[index][openBracketCount] != -1)
            return dp[index][openBracketCount];
        int validString = 0;
        if (s[index] == '(')
            validString |= usingDP(s, index + 1, n, openBracketCount + 1, dp);
        else if (s[index] == ')')
        {
            if (openBracketCount > 0)
                validString |= usingDP(s, index + 1, n, openBracketCount - 1, dp);
        }
        else
        {
            // Taking * as NULL
            validString |= usingDP(s, index + 1, n, openBracketCount, dp);
            // Taking * as (
            validString |= usingDP(s, index + 1, n, openBracketCount + 1, dp);
            // Taking * as )
            if (openBracketCount > 0)
                validString |= usingDP(s, index + 1, n, openBracketCount - 1, dp);
        }
        return dp[index][openBracketCount] = validString;
    }

    bool usingTwoStacks(string &s)
    {
        // these two will store the indexes of openBrackets and asterisks respectively
        stack<int> openBrackets, asterisk;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                openBrackets.push(i);
            else if (s[i] == ')')
            {
                if (!openBrackets.empty())
                    openBrackets.pop();
                else if (!asterisk.empty())
                    asterisk.pop();
                else
                    return false;
            }
            else
            {
                asterisk.push(i);
            }
        }
        while (!openBrackets.empty() && !asterisk.empty())
        {
            // if openBracket comes after the asterisk
            if (openBrackets.top() > asterisk.top())
                return false;
            openBrackets.pop();
            asterisk.pop();
        }
        if (!openBrackets.empty())
            return false;
        return true;
    }

    bool usingTwoPointers(string s)
    {
        int openCount = 0;
        int closeCount = 0;
        int length = s.length() - 1;

        // Traverse the string from both ends simultaneously
        for (int i = 0; i <= length; i++)
        {
            // Count open parentheses or asterisks
            if (s[i] == '(' || s[i] == '*')
            {
                openCount++;
            }
            else
            {
                openCount--;
            }

            // Count close parentheses or asterisks
            if (s[length - i] == ')' || s[length - i] == '*')
            {
                closeCount++;
            }
            else
            {
                closeCount--;
            }

            // If at any point open count or close count goes negative, the string is invalid
            if (openCount < 0 || closeCount < 0)
            {
                return false;
            }
        }

        // If open count and close count are both non-negative, the string is valid
        return true;
    }
    bool checkValidString(string s)
    {
        int n = s.length();
        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return usingDP(s,0,n,0,dp); // BRUTE

        // return usingTwoStacks(s); // BETTER
        return usingTwoPointers(s); // OPTIMAL
    }
};