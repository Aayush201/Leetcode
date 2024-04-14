/*
Problem Link : https://leetcode.com/problems/maximum-prime-difference/description/
*/

class Solution
{
public:
    int yes(int n)
    {
        int cnt = 0;
        if (n <= 1)
            return 0;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return 0;
        }
        return 1;
    }
    int maximumPrimeDifference(vector<int> &nums)
    {
        int i1 = INT_MAX, i2 = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
            if (yes(nums[i]))
            {
                i1 = min(i1, i);
                i2 = max(i2, i);
            }
        cout << i1 << " " << i2 << endl;
        return abs(i1 - i2);
    }
};