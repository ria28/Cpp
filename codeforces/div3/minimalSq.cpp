#include <iostream>
#include <climits>
#include <math.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        float a, b;
        cin >> a >> b;
        if (a != b)
        {
            float rec_ar = 2 * (a * b);
            float ele = sqrt(rec_ar);
            // cout << ele << "\n";
            int side = ceil(ele);
            // cout << side << "\n";
            cout << (side * side)<<"\n";
        }
        else
        {
            cout<<(2*a)*(2*a)<<"\n";
        }
        
    }

    return 0;
}