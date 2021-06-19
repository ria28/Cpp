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
#define vi vector<int>
#define vii vector<vector<int>>

vi par;
vi rank_;

void makeset(int N)
{
    par.resize(N+1);
    rank_.resize(N+1);

    for(int i =0; i<=N;i++)
    {
        par[i]=i;
        rank_[i]=1;
    }
}

int find(int a)
{
    if(par[a] == a)
        return a;
    // return find(par[a]);
    int temp = find(par[a]);
    par[a] = temp;
    return temp;
}

void Union(int a , int b)
{
    if(rank_[a] > rank_[b])
    {
        rank_[a] += rank_[b];
        par[b] = a;
    }
    else
    {
        rank_[b] += rank_[a];
        par[a] = b;
    }
}

bool comp(vector<int>&a , vector<int> &b)
{
    return a[2]<b[2];
}

int minimumCost(int N, vector<vector<int>> &connections)
{
    sort(connections.begin() , connections.end() , comp);

    //  sort(connections.begin(), connections.end(),
    //         [](const vector<int> &a, const vector<int> &b) {
    //             return a[2] < b[2];

    makeset(N);
    int cost =0;
    int total = 0;
    for(int i =0; i<connections.size(); i++)
    {
        int par1 = find(connections[i][0]);
        int par2 = find(connections[i][1]);

        if(par1 != par2)
        {
            Union(par1 , par2);
            total ++;
            cost += connections[i][2];
        }
    }

    cout<<total <<" "<<cost;

    if(total == N-1)
    {
        return cost;
    }
    else
        return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n =3;
    vii conn = { {1,2,5} , { 1,3,6} , {2,3,1} };
    cout<<minimumCost(n, conn);
    return 0;
}