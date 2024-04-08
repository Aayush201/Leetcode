/*
Problem Link : https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08
*/

class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int zeroes = 0, ones = 0;
        for (auto x : students)
            x ? ones++ : zeroes++;
        int n = sandwiches.size();
        int i = 0;
        for (i = 0; i < n; i++)
        {
            sandwiches[i] ? ones-- : zeroes--;
            if (ones < 0 || zeroes < 0)
                break;
        }
        return n - i;
    }
};