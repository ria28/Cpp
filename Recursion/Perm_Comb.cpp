#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <vector>
#include <string>
using namespace std;

// look at combinationalSum for better idea of perm comb with rep without rep


static int cnt = 0;

void distinct_word_perm(string uniq_str, int k, string asf, int idx)
{
    // PENDING  **************_______________***************
     
    //https://www.youtube.com/watch?v=ZmAoj7wpMvM&list=PL-Jc9J83PIiHO9SQ6lxGuDsZNt2mkHEn0&index=28
}

//abcabc
void wordkSelection(string uniq_str, int k, string asf, int idx)
{
    if (asf.size() == k)
    {
        cout << ++cnt << " " << asf << "\n";
        return;
    }
    for (int i = idx; i < uniq_str.size(); i++)
    {
        wordkSelection(uniq_str, k, asf + uniq_str[i], i + 1);
    }
}

//aabb
void string_perm(string uni_str, int n, unordered_map<char, int> &map, string asf)
{
    if (asf.size() == n)
    {
        cout << ++cnt << ": ";
        cout << asf << "\n";
        return;
    }
    for (int i = 0; i < uni_str.size(); i++)
    {
        if (map[uni_str[i]] > 0)
        {
            map[uni_str[i]]--;
            string_perm(uni_str, n, map, asf + uni_str[i]);
            map[uni_str[i]]++;
        }
    }
}

void comb(vector<int> &box, int ci, int ti, int idx)
{
    if (ci > ti)
    {
        cout << ++cnt << ": ";
        for (int i = 0; i < box.size(); i++)
        {
            cout << box[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = idx; i < box.size(); i++)
    {
        if (box[i] == 0)
        {
            box[i] = ci;
            comb(box, ci + 1, ti, i + 1);
            box[i] = 0;
        }
    }
}

void comb_(int ci, int ti, int ssf, int ts, string asf) // ssf : selection so far, ts : total selections , ri: total items , ci : current item
{

    if (ci > ts)
    {
        if (ssf == ti)
        {
            cout << "ans:";
            cout << asf << "\n";
        }
        return;
    }

    comb_(ci + 1, ti, ssf, ts, asf + "-");
    comb_(ci + 1, ti, ssf + 1, ts, asf + 'i');
}

void perm(vector<int> &box, int ci, int ti) // ci : current ele , ti : total ele
{
    if (ci > ti)
    {
        cout << ++cnt << ".  ";
        for (int i : box)
        {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < box.size(); i++)
    {
        if (box[i] == 0)
        {
            box[i] = ci;
            perm(box, ci + 1, ti);
            box[i] = 0;
        }
    }
}

int main()
{
    // permutation----------------------------------------------------------------
    // int n, ti;
    // cin >> n;
    // cin >> ti;
    // vector<int> box(n, 0);
    // perm(box, 1, ti);
    // comb_(1, ti, 0, n, "");
    // comb(box, 1, ti, 0);

    // string perm ----------------------------------------------------------------
    string str;
    cin >> str;
    // unordered_map<char, int> map;
    // string uni_str = "";
    // for (int i = 0; i < str.size(); i++)
    // {
    //     if (map.find(str[i]) == map.end())
    //     {
    //         uni_str += str[i];
    //         map[str[i]] = 1;
    //     }
    //     else
    //     {
    //         map[str[i]]++;
    //     }
    // }
    // string_perm(uni_str, str.size(), map, "");

    // word K selection, K Distinct Characters without Repetition using------------------------
    int k;
    cin >> k;
    unordered_set<char> set;
    string uniq_str = "";
    for (int i = 0; i < str.size(); i++)
    {
        if (set.find(str[i]) == set.end())
        {
            set.insert(str[i]);
            uniq_str += str[i];
        }
    }
    wordkSelection(uniq_str, k, "", 0);
    return 0;
}
