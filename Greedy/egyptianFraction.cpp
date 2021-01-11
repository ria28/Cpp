#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)

// https://www.geeksforgeeks.org/greedy-algorithm-egyptian-fraction/

// 6/14

void printEgyptian(int nr, int dr)
{
    if (nr % dr == 0)
    {
        cout << "not possible . Nr is divi by dr  " << nr / dr;
        return;
    }
    if (dr % nr == 0)
    {
        cout << 1 << "/" << dr / nr;
        return;
    }
    if (nr > dr)
    {
        cout << nr << " + ";
        printEgyptian(nr % dr, dr);
        return;
    }

    int new_nr = dr / nr + 1; // instead of ceil we just add 1 to it bcoz nos are not in float ... if nos were in float then we would have used ceil
    cout << "1/" << new_nr << " + ";
    printEgyptian(nr * new_nr - dr, dr * new_nr);
    // return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // int nr = 6, dr = 14;
    int nr = 12;
    int dr = 13;
    cout << "Egyptian Fraction Representation of "
         << nr << "/" << dr << " is\n ";
    printEgyptian(nr, dr);
    return 0;
}