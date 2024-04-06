/*
Problem Link : https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/
*/

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        int ans = INT_MAX, i = 0, j = 0, n = cards.size();
        unordered_map<int, int> mp;
        while (j < n)
        {
            mp[cards[j]]++;
            while (i <= j && mp[cards[j]] >= 2)
            {
                ans = min(ans, j - i + 1);
                mp[cards[i]]--;
                if (!mp[cards[i]])
                    mp.erase(cards[i]);
                i++;
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};