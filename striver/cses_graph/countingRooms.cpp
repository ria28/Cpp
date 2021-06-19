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

void dfs(int  i , int j , vector<vector<char>>&arr)
{
    if(i<0 || j<0 || i>=arr.size() || j>=arr[0].size() || arr[i][j] != '.')
        return;
    
    arr[i][j] = '#';
    dfs(i-1,j,arr);
    dfs(i,j+1 , arr);
    dfs(i+1 , j , arr);
    dfs(i, j-1,arr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    vector<vector<char>>arr(n,vector<char>(m));
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<m;j++)
        {
            char ele;
            cin>>ele;
            arr[i][j] =ele; 
        }
    }

    // vector<vector
    int cnt =0;
    for(int i =0; i<n;i++)
    {
        for(int j =0; j<m;j++)
        {
            if(arr[i][j] == '.')
            {
                cnt++;
                dfs(i,j,arr);
            }
        }
    }

    cout<<cnt;
    return 0;
}