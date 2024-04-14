/*
Problem Link : https://leetcode.com/problems/minimum-rectangles-to-cover-points/description/
*/

class Solution
{
public:
    int minRectanglesToCoverPoints(vector<vector<int>> &points, int w)
    {
        int ans = 1;
        sort(points.begin(), points.end());
        int prev = points[0][0];
        for (int i = 1; i < points.size(); i++)
        {
            if ((points[i][0] - prev) <= w)
                continue;
            else
            {
                prev = points[i][0];
                ans++;
            }
        }
        return ans;
    }
};