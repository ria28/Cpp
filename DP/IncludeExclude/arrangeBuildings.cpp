#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include<math.h>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

// same as binary counts
void arrange(int n)
{
    int b_prev = 1;
    int s_prev = 1;
    int b_next, s_next;
    for (int i = 2; i <= n; i++)
    {
        b_next = s_prev;
        s_next = b_prev + s_prev;
        b_prev = b_next;
        s_prev = s_next;
    }
    cout << pow(b_next + s_next,2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    arrange(n);
    return 0;
}