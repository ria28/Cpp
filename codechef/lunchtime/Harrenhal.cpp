#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool is_palin(string str, int s, int e)
{
    if (s == e)
        return true;
    if (str[s] != str[e])
        return false;

    if (s < e + 1)
        return is_palin(str, s + 1, e - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0) {
        string h;
        cin >> h;

        // if the string is already palindromic, then one set of troops suffices
        // otherwise two are needed - first all as, then all bs
        bool palindromic = true;
        for (size_t i = 0, j = h.length() - 1; i < j; i++, j--) {
            if (h[i] != h[j]) {
                palindromic = false;
                break;
            }
        }

        cout << (palindromic ? 1 : 2) << '\n';
    }

    return 0;
}