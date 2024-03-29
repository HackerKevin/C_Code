#define _CRT_SECURE_NO_WARNINGS	1
#include "UnionFindSet.h"
#include "Graph.h"

class Solution1 {
public:
    bool equationsPossible(vector<string>& equations) 
    {
        vector<int> ufs(26, -1);

        auto findRoot = [&ufs](int x)
        {
            while (ufs[x] >= 0)
            {
                x = ufs[x];
            }
            return x;
        };

        // 第一遍，先把相等的值加到一个集合中
        for (auto& str : equations)
        {
            if (str[1] == '=')
            {
                int root1 = findRoot(str[0]-'a');
                int root2 = findRoot(str[3]-'a');

                if (root1 != root2)
                {
                    ufs[root1] += ufs[root2];
                    ufs[root2] = root1;
                }
            }
        }

        // 第二遍，判断不相等的在不在一个集合，如果在则相悖
        for (auto& str : equations)
        {
            if (str[1] == '!')
            {
                int root1 = findRoot(str[0] - 'a');
                int root2 = findRoot(str[3] - 'a');

                if (root1 == root2)
                {
                    return false;
                }


            }
        }

        return true;
    }
};

int main()
{
   
    Martix::TestGraph();
    return 0;
}
