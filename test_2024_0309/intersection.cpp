// 349.两个数组的交集
#include "Assistance.h"

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        // 排序 + 去重
        // sort(nums1.begin(), nums1.end());
        // unique(nums1.begin(), nums1.end());
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2(nums2.begin(), nums2.end());

        auto it1 = s1.begin();
        auto it2 = s2.begin();
        vector<int> v;
        while (it1 != s1.end() && it2 != s2.end())
        {
            if (*it1 < *it2)
            {
                ++it1;
            }
            else if (*it1 > *it2)
            {
                it2++;
            }
            else
            {
                v.push_back(*it1);
                ++it1;
                ++it2;
            }
        }
        return v;
    }
};