#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

// https://leetcode.com/problems/partition-labels/

vector<int> partitionLabels(string S)
{
    vector<int> last(26);
    for (int i = 0; i < S.size(); i++)
    {
        last[S[i] - 'a'] = i;
    }

    int start_of_partition = 0, last_of_each_block = 0;
    vector<int> ans;
    for (int i = 0; i < S.size(); i++)
    {
        last_of_each_block = max(last_of_each_block, last[S[i] - 'a']);
        if (i == last_of_each_block)
        {
            ans.push_back(last_of_each_block - start_of_partition + 1);
            start_of_partition = i + 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str = "ababcbacadefegdehijhklij";
    vector<int> ans = partitionLabels(str);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}