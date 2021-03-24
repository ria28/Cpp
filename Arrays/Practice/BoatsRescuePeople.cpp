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

int numRescueBoats(vector<int> &people, int limit)
{
    sort(people.begin(), people.end());
    int j = people.size()-1;
    int cnt =0;
    for(int i =0; i<j;)
    {
        if(people[i] + people[j] <= limit)
        {
            cnt++;
            j--;
            i++;
        }
        else
        {
            j--;
            cnt++;
        }   
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}