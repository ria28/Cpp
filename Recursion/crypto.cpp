#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
using namespace std;

int getNum(string s, unordered_map<char, int> &map)
{
    int no = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (map.find(s[i]) != map.end())
        {
            no = no * 10 + map[s[i]];
        }
    }
    return no;
}

void crypto(string unique, int idx, vector<bool> &usedNos, unordered_map<char, int> &map, string s1, string s2, string s3)
{
    if (idx == unique.size())
    {
        int num1 = getNum(s1, map);
        int num2 = getNum(s2, map);
        int num3 = getNum(s3, map);

        if (num1 + num2 == num3)
        {
            for (int i = 0; i < 26; i++)
            {
                char a = 'a' + i;
                if (map.find(a) != map.end())
                {
                    cout << a << "->" << map[a];
                }
            }
        }
    }
    char s = unique[idx];        // LEVELS  ----> inside the func fetching with idx
    for (int i = 0; i <= 9; i++) // 0 1 2 3 4 5 6 7 8 9 ---> OPTIONS so in the loop
    {
        if (!usedNos[i])
        {
            map[s] = i;
            usedNos[i] = true;
            crypto(unique, idx + 1, usedNos, map, s1, s2, s3);
            usedNos[i] = false;
            map[s] = -1;
        }
    }
}

static bool flag = false;
void crypto_leet_util(string unique, vector<bool> &usedNos, unordered_set<char> &set, vector<int> &charCount, int idx, int dif)
{
    if (idx == unique.size())
    {
        // cout<<"krl";
        if (dif == 0)
        {
            flag = true;
            // cout << "yes";
        }
        return;
    }
    // cout << dif << " ";
    char s = unique[idx];

    for (int i = 0; i <= 9; i++)
    {
        if (!usedNos[i])
        {
            if (i == 0 && set.find(s) != set.end())
                continue;

            usedNos[i] = true;
            // map[s] = i;
            // cout << charCount[s]<<" ";
            crypto_leet_util(unique, usedNos, set, charCount, idx + 1, dif + charCount[s-97] * i);
            usedNos[i] = false;
            // map[s] = -1;
        }
    }
}

bool isSolvable(vector<string> &words, string res)
{
    // unordered_map<char, int> map;
    unordered_set<char> set;
    unordered_set<char> set2;
    vector<int> charCount(28, 0);
    string unique = "";
    for (int i = 0; i < words.size(); i++)
    {
        string s = words[i];
        for (int j = 0; j < s.size(); j++)
        {
            if (set2.find(s[j]) == set2.end())
            {
                if (j == 0)
                {
                    set.insert(s[j]);
                }
                set2.insert(s[j]);
                // map[s[j]] = -1;
                unique += s[j];
            }
            // cout<<charCount[s[j]]<<" ";
            charCount[s[j]-97] += pow(10, (s.size() - j - 1));
            // cout<<pow(10, (s.size() - j - 1))<<" ";
            // cout << s[j] << " : " << charCount[s[j]]<<"\n";
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (set2.find(res[i]) == set2.end())
        {
            if (i == 0)
            {
                set.insert(res[i]);
            }
            // map[res[i]] = -1;
            set2.insert(res[i]);
            unique += res[i];
        }

        // cout<<charCount[res[i]]<<" ";
        charCount[res[i]-97] -= pow(10, res.size() - i - 1);
        
        // cout << res[i] << " : " << charCount[res[i]]<<"\n";
    }
    // for (int i = 0; i < charCount.size(); i++)
    // {
    //     cout << charCount[i];
    // }
    // cout<<unique<<" ";
    vector<bool> usedNos(10, false);
    crypto_leet_util(unique, usedNos, set, charCount, 0, 0);
    return flag;
}

int main()
{
    // send more money
    // unique  str: "s e n d m o r y"
    // string s1, s2, s3;
    // cin >> s1 >> s2 >> s3;
    // unordered_map<char, int> map;
    // string unique = "";
    // for (int i = 0; i < s1.size(); i++)
    // {
    //     if (map.find(s1[i]) == map.end())
    //     {
    //         map[s1[i]] = -1;
    //         unique += s1[i];
    //     }
    // }
    // for (int i = 0; i < s2.size(); i++)
    // {
    //     if (map.find(s2[i]) == map.end())
    //     {
    //         map[s2[i]] = -1;
    //         unique += s2[i];
    //     }
    // }
    // for (int i = 0; i < s3.size(); i++)
    // {
    //     if (map.find(s3[i]) == map.end())
    //     {
    //         map[s3[i]] = -1;
    //         unique += s3[i];
    //     }
    // }
    // vector<bool> usedNos(10, false);
    // crypto(unique, 0, usedNos, map, s1, s2, s3);

    //  LEETCODE : https://leetcode.com/problems/verbal-arithmetic-puzzle/
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }
    string res;
    cin >> res;
    cout << boolalpha << isSolvable(words, res);

    return 0;
}