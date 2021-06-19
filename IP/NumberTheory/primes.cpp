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

ll m = 1e4;
vector<ll>arr;
vector<bool>isPrime(m, true);
void prime()
{
    for(int i =2;i<m;i++)
    {
        if(isPrime[i])
        {
            arr.push_back(i);
            for(int j =i*i ; j<m;j+=i)
            {
                isPrime[j]=false;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    prime();
    
    for(int i =0; i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}