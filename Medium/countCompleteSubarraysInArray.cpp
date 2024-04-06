/*
https : // leetcode.com/problems/count-complete-subarrays-in-an-array/description/
*/
class Solution
{
public:
    int countCompleteSubarrays(vector<int> &nums)
    {
        int ans = 0, i = 0, j = 0, n = nums.size();
        unordered_map<int, int> mp;
        for (auto x : nums)
            mp[x]++;
        int k = mp.size();
        mp.clear();
        // cout << k << endl;
        while (j < n)
        {
            mp[nums[j]]++;
            while (i <= j && mp.size() == k)
            {
                ans += n - j;
                mp[nums[i]]--;
                if (!mp[nums[i]])
                    mp.erase(nums[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};