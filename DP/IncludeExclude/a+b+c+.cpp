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

// https://www.youtube.com/watch?v=IV9pbZsi5cc&list=PL-Jc9J83PIiG8fE6rj9F5a6uyQ5WPdqKy&index=21
void subse(string str)
{
    int a = 0;
    int ab = 0;
    int abc = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'a')
        {
            a = 2 * a + 1;
        }
        else if (str[i] == 'b')
        {
            ab = 2 * ab + a;
        }
        else // str[i] == 'c'
        {
            abc = 2 * abc + ab;
        }
    }

    cout<<abc<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    str = "abcabc";
    subse(str);
    return 0;
}