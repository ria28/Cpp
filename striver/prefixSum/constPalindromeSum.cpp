//https://codeforces.com/problemset/problem/1343/D
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int ele;
            cin >> ele;
            arr.push_back(ele);
        }

        // 6 1 1 6 7 3 4 6
        unordered_map<int, int> map;      // cnt_0 changes
        vector<int> presum(2 * k + 5, 0); // changes with 0/1 change
        for (int i = 0; i < n / 2; i++)
        {
            int fir = arr[i];
            int sec = arr[n - i - 1];
            int L = min(fir, sec) + 1;
            int R = max(fir, sec) + k;
            presum[L] += 1;
            presum[R + 1] -= 1;

            map[fir + sec]++;
        }

        int sum = 0;
        for (int i = 1; i < presum.size(); i++)
        {
            presum[i] += sum;
            sum = presum[i];
        }
        // for (auto i : presum)
        //     cout << i << " ";

        int min_changes = n;
        for (int x = 2; x <= 2 * k; x++)
        {
            int cnt_0 = 0;
            if (map.find(x) != map.end())
                cnt_0 = map[x];
            int cnt_1 = presum[x] - cnt_0;
            int cnt_2 = (n / 2) - cnt_0 - cnt_1;
            int cnt = cnt_1 + (cnt_2*2);

            min_changes = min(min_changes, cnt);
        }

        cout << min_changes << "\n";
    }
}


/* 
    -> (even) n sized array  ->constant palin sum (sum[last+frst] = sum [secondlast + second] = ...)
    -> min changes in the no. that we can do to make const palin sum by only appending the no. from 1 to k [1,2,3...k]
    -> given each no is smaller / equal to k

    eg . (n,k ) -->  8 7
        [ 6 1 1 7 6 3 4 6]
         
        palin pairs
        (6,6)  , (1,4) , (1,3)  , (6,7)

        min change no and max change no can cause L ( by adding 1 to min no.), R(by adding k to max no)
        (6,6) : L = 7,  R = 13
        (1,4) : L = min(1,4) +1 = 2 ,  R = max(1,4) + k = 4 + 7 = 11
        (1,3) : L = 2 , R = 10
        (6,7) : L = 7 , R = 14

        presum[]  ---> 0/1 changes 
        0   1    2    3    4    5     6    7    8   9   10    11   12    13    14    15
        0        2                         2                  -1   -1          -1    -1


        0   1    2    3    4    5     6    7    8   9   10    11   12    13    14   15
        0   0    2    2    2    2     2    4    4   4    3     2    2     2     1   0

        cnt_0 --> if present in map;
        cnt_1 --> presum[x] - cnt_0
        cnt_2 ---> total_pairs - cnt_0 -cnt_1
        total cnt = cnt_1 + (2*cnt_2) // 


 */