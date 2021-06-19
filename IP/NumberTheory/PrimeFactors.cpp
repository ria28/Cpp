
    #include <iostream>
    #include <string>
    #include <unordered_set>
    #include <unordered_map>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <climits>
    #include <math.h>
    #define ll long long
    using namespace std;
    #define f_loop(i, s, e) for (int i = s; i < e; i++)
    #define f_long(i, s, e) for (long long i = s; i < e; i++)
    #define vi vector<int>
    #define vii vector<vector<int>>

    void segmentedSieve(long long L, long long R)
    {
        // generate all primes up to sqrt(R)
        long long lim = sqrt(R);
        vector<bool> isPrime(lim + 1, true);
        vector<long long> primes;
        for (long long i = 2; i <= lim; ++i)
        {
            if (isPrime[i])
            {
                // cout<<i<<" ";
                primes.emplace_back(i);
                for (long long j = i * i; j <= lim; j += i)
                    isPrime[j] = false;
            }
        }

        vector<bool> isPrime_(R - L + 1, true);
        for (long long p : primes)
        {
            // cout<<p<<" ";
            // ll factor = ceil(L / p * 1.0);
            for (long long j = max(p * p, ((L + p - 1) / p) * p); j <= R; j += p)
            {
                isPrime_[j - L] = false;
            }
        }

        if (L == 1)
            isPrime_[0] = false;

        vector<ll> res;
        for (int i = 0; i < isPrime_.size(); i++)
            if (isPrime_[i])
                res.push_back(L + i);

        // for (int i = 0; i < res.size(); i++)   // list of primes till R
        //     cout << res[i] << "\n";

        unordered_set<ll> set;    // almost prime question codeforces exactly  2 prime divisors 
        ll cnt = 0;
        for (int i = 2; i <= R; i++)
        {
            ll temp = i;
            set.clear();
            for (int j = 0; j < res.size(); j++)
            {
                bool flag = true;
                while (i % res[j] == 0 && temp != res[j])
                {
                    set.insert(res[j]);
                    i = i / res[j];
                }
            }
            if (set.size() == 2)
                cnt++;
            i = temp;
            // cout << "cnt" << i << cnt << " ";
        }
        cout << cnt;
    }

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        segmentedSieve(1, n);

        return 0;
    }
