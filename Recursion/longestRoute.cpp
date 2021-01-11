#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define vvi vector<vector<int>>
using namespace std;

void findLongestPath(vvi &mat, vector<vector<bool>>& vis)
{
    
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    vvi mat = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

    vector<vector<bool>> vis(mat.size(), vector<bool>(mat[0].size(),false));
    findLongestPath(mat, vis);
    return 0;
}