/*
Problem Link : https://leetcode.com/problems/subarrays-with-k-different-integers/description/
*/

class Solution
{
public:
    int solve(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        int i = 0, j = 0, ans = 0, n = nums.size();
        while (j < n)
        {
            mp[nums[j]]++;
            while (i <= j && mp.size() > k)
            {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        // to find exactly k first we will calculate all the subarrays with <=k
        // and then we will find all the subarrays with <=(k-1) and subtract them
        int countk = solve(nums, k);
        int countkminusone = solve(nums, k - 1);
        return countk - countkminusone;
    }
};