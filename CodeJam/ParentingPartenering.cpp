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

class tri
{
public:
    int end;
    int start;
    string ans;
    tri(int end, int start, string ans)
    {
        this->end = end;
        this->start = start;
        this->ans = ans;
    }
};

bool comapare(tri a, tri b)
{
    return a.end < b.end;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    int T =1;
    while(T<=t)
    {
        
    }
    return 0;
}