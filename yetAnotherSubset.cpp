#include "bits/stdc++.h"
using namespace std;

#define MAXN 100001

int spf[MAXN];
long long mod = 1e9 + 7;
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j < MAXN; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

unordered_set<int> set_;
void getFactorization(int x)
{
    while (x != 1)
    {
        if (set_.find(spf[x]) != set_.end())
        {
            set_.clear();
            return;
        }
        set_.insert(spf[x]);
        x = x / spf[x];
    }
}

int main(int argc, char const *argv[])
{
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr;
        set_.clear();
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            if (set_.find(ele) == set_.end())
            {
                set_.insert(ele);
                arr.push_back(ele);
            }            
        }
        set_.clear();

        unordered_map<int, int> map;
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            set_.clear();
            getFactorization(arr[i]);
            if (set_.size() == 0)
                continue;
            else
            {
                cnt++;
                for (auto s : set_)
                {
                    map[s]++;
                }
            }
        }

        int tot_cnt_subsets = pow(2, cnt) - 1; // excl empty subset
        int rep = 0;
        bool toge = true;
        for (auto m : map)
        {
            if (m.second > 1)
            {
                if (m.second != cnt)
                    toge = false;
                rep = pow(2, m.second) - m.second - 1;
                tot_cnt_subsets = tot_cnt_subsets - rep;
            }
        }
        if (!toge)
            tot_cnt_subsets--;
        cout << tot_cnt_subsets << "\n";
    }
    return 0;
}
