// 692 前 K 个高频单词
#include "Assistance.h"

class Solution {
public:
    struct Compare
    {
        bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2)
        {
            return kv1.second > kv2.second 
               || (kv1.second == kv2.second && kv1.first < kv2.first);
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        // 先统计次数
        map<string, int> countMap;
        for (auto& str : words)
        {
            countMap[str]++;
        }

        vector<pair<string, int>> v(countMap.begin(), countMap.end());

        // stable_sort(v.begin(), v.end(), Compare());
        sort(v.begin(), v.end(), Compare());

        vector<string> ret;
        
        for (size_t i = 0; i < k; i++)
        {
            ret.push_back(v[i].first);
        }

        return ret;

    }
    vector<string> TopKFrequent(vector<string>& words, int k)
    {
        // 先统计次数
        map<string, int> countMap;
        for (auto& str : words)
        {
            countMap[str]++;
        }

        multimap<int, string, Compare> sortMap;
        for (auto& kv : countMap)
        {
            sortMap.insert(make_pair(kv.second, kv.first));
        }

        vector<string> ret;
        auto it = sortMap.begin();
        while (k--)
        {
            ret.push_back(it->second);
            ++it;
        }
    }
};

