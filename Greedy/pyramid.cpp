#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

// https://www.geeksforgeeks.org/find-maximum-height-pyramid-from-the-given-array-of-objects/

// No. of levels = Maximum height is asked
// Levels Elements needed
// 1 1
// 2 1+2
// 3 1+2+3
// 4 1+2+3+4
// so, for height=L , elements needed = L(L+1)/2

void pyramidHeight(int n)
{
    cout << (-1 + floor(sqrt(1 + 8 * n))) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int noOfEle;
    cin >> noOfEle;
    pyramidHeight(noOfEle);

    return 0;
}