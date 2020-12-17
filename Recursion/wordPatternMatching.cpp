#include <iostream>
#include <unordered_map>
using namespace std;

// treegraphtree
// pep
// p--->tree , e--->graph
void pattern(string str, string pat, int pat_idx, unordered_map<char, string> &map)
{
    if (pat_idx == pat.size())
    {
        if (str.size() == 0)
        {
            for (auto i : map)
            {
                cout << i.first << "-->" << i.second << "\n";
            }
        }
        return;
    }
    char ch = pat[pat_idx];
    if (map.find(ch) == map.end())
    {
        for (int i = 0; i < str.size(); i++)
        {
            string left = str.substr(0, i + 1);
            string right = str.substr(i + 1, str.size());
            map[ch] = left;
            pattern(right, pat, pat_idx + 1, map);
            map.erase(ch);
        }
    }
    else
    {
        string prevMapping = map[ch];
        if (str.size() >= prevMapping.size() && prevMapping == str.substr(0, prevMapping.size()))
        {
            string right = str.substr(prevMapping.size());
            pattern(right, pat, pat_idx + 1, map);
        }
    }
}

int main()
{
    string str, pat;
    cin >> str >> pat;
    unordered_map<char, string> map;
    pattern(str, pat, 0, map);
    return 0;
}