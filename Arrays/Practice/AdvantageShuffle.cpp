#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<int>
#define vii vector<vector<int>>

#include <set> // multiset
class Solution
{
public:
    vector<int> advantageCount(vector<int> &A, vector<int> &B)
    {
        multiset<int> ms;
        for (int i = 0; i < A.size(); i++)
            ms.insert(A[i]);

        // for(auto itr = ms.begin() ; itr != ms.end() ; itr++)
        //     cout<<*(itr)<<" ";

        vector<int> ans(A.size());

        for (int i = 0; i < B.size(); i++)
        {
            auto it = ms.upper_bound(B[i]);
            // cout<<*(it)<<" ";
            if (it != ms.end())
            {
                A[i] = *it;
            }
            else
            {
                it = ms.begin();
                A[i] = *it;
            }
            ms.erase(it);
        }
        return A;
    }
};