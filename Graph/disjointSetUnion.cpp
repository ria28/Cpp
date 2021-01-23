#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;

// struct Node
// {
//     int data;
//     Node *par;
//     int rank;
// };

static vector<int> par;
static vector<int> rank_;

void makeSet(int data)
{
    par[data] = data;
    rank_[data] = 0;
}

int findPar(int data)
{
    if (data == par[data])
    {
        return data;
    }
    return findPar(par[data]);
}

void union_(int data1, int data2)
{
    int par1 = findPar(data1);
    int par2 = findPar(data2);

    if (par1 == par2)
        return;
    if (rank_[par1] == rank_[par2])
    {
        par[data2] = data1;
        rank_[par1]++;
    }
    else if (rank_[par1] > rank_[par2])
    {
        par[par2] = data1;
    }
    else
    {
        par[par1] = data2;
    }
}

void dsu()
{
    par.resize(7);
    rank_.resize(7);
    makeSet(1);
    makeSet(2);
    makeSet(3);
    makeSet(4);
    makeSet(5);
    makeSet(6);
    makeSet(7);

    union_(1, 2);
    union_(2, 3);
    union_(4, 5);
    union_(6, 7);
    union_(5, 6);
    union_(3, 7);
    for (int i = 1; i <= 7; i++)
    {
        cout << i << ":" << findPar(i) << ":" << rank_[i] << "\n";
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    dsu();
    return 0;
}