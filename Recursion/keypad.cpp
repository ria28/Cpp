#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

void comb(unordered_map<char, string> &map, string str, int k, int idx, string asf, vector<string> &ans)
{
    // cout<<str[idx]<<" ";
    if (k == 0)
    {
        ans.push_back(asf);
        // cout << asf << "\n";
        return;
    }
    string alp = map[str[idx]];
    
    for (int i = 0; i < alp.size(); i++)
    {
        comb(map, str, k - 1, idx + 1, asf + alp[i], ans);
    }
}

vector<string> letterCombinations(string digits)
{
    unordered_map<char, string> map;
    map.insert({'2', "abc"});
    map.insert({'3', "def"});
    map.insert({'4', "ghi"});
    map.insert({'5', "jkl"});
    map.insert({'6', "mno"});
    map.insert({'7', "pqrs"});
    map.insert({'8', "tuv"});
    map.insert({'9', "wxyz"});

    vector<string> ans;
    comb(map, digits, digits.size(), 0, "", ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    letterCombinations("23");
    return 0;
}