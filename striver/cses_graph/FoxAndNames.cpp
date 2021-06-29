#include<bits/stdc++.h>
using namespace std;

vector<int>inorder(26,0);
vector<char>ans(26);
const int maxn = 1e3 + 5;
bool topo(vector<vector<int>>&gp)
{
    queue<int>q;
    for(int i =0; i<26;i++)
    {
        if(inorder[i]==0)
            q.push(i);
    }
    
    int cnt =0;
    while(!q.empty())
    {
        int ele = q.front();
        q.pop();
        ans[cnt ++ ] = ele + 'a';

        for(int i : gp[ele])
        {
            inorder[i]--;
            if(inorder[i] ==0)
            q.push(i);
        }
    }

    return cnt >=26;
}

char arr[maxn][maxn];
int main()
{
    int n ;
    cin>>n;
    // vector<vector<char>>arr(maxn , vector<char>(maxn));
    for(int i =0; i<n;i++)
    {
        cin>>arr[i];
    }

    vector<vector<int>>gp(26);
    
    for(int i =0; i<n-1;i++)
    {
        int len1 = strlen(arr[i]);
        int len2 = strlen(arr[i+1]);
        bool flag = false;
        for(int j =0; j<min(len1 , len2);j++)
        {
            if(arr[i][j] != arr[i+1][j])
            {
                gp[arr[i][j]-'a'].push_back(arr[i+1][j]-'a');
                inorder[arr[i+1][j]-'a']++;
                flag = true;
                break;
            }
        }

        if(!flag && len1 >len2)
        {
            // cout<<"wrfw";
            cout<<"Impossible";
            return 0;
        }
    }

    if(!topo(gp))
    {
        cout<<"Impossible";
        return 0;
    }

    for(char c : ans)
    cout<<c;
    return 0;
    
}