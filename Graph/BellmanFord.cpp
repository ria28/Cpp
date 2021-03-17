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
/* 

    negative edge weight : some edges have negative weight : SHORTEST PATH ALLOWED  -->> BELLMAN 
    negative weight cycle : (sum of all weights of cycle is negative) : SHORTEST PATH DOESN'T EXISTS
    (you will keep on revolving in the cycle  infinite time because the sum is -2 and u'll keep on adding -2 to make it shorter :| )


*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
