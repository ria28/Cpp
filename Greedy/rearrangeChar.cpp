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

// bool comp(pair<int,char>&a,pair<int,char>&b)
// {
//     return
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    priority_queue<pair<int, char>, vector<pair<int, char>>> maxHeap;
    vector<int> freq(26, 0);
    for (char i : str)
        freq[i - 'a']++;
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (freq[i - 'a'])
            maxHeap.push(make_pair(freq[i - 'a'], i));
    }

    string res = "";
    pair<int, char> prev = {-1, '#'};
    while (!maxHeap.empty())
    {
        pair<int, char> p = maxHeap.top();
        maxHeap.pop();
        // cout << p.first << " " << p.second << "\n";
            res += p.second;
        if (prev.first > 0)
        {
            maxHeap.push(prev);
        }
        p.first--;
        prev = p;

    }
    cout << res << "\n";

    return 0;
}