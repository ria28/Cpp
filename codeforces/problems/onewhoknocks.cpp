#include <iostream>
#include <algorithm>
using namespace std;
int solve(int n1, int n2)
{
    // val of a and b will remain constant throughout
    int dif = n2 - n1;
    if (dif > 0) //case 1
    {
        if (dif % 2 == 0)
        {
            if (dif % 4 == 0) // case 1.1 : X =0; , Y = 4 -------->(X +3 +3 -2)------> 3 rounds
                return 3;
            else // case 1.2 : X = 0 , Y =10 ------> (X + 5 + 5)----> 2 rounds
                return 2;
        }
        else
            return 1; // odd differance Case 1.3  X = 1 , Y = 4 ----------> (X+3) ----> 1 round
    }
    else if (dif < 0) // Case 2
    {
        if (dif % 2 == 0) // case 2.1 X =0, Y = -4  ------> (x -4)---> 1 round
            return 1;
        else // case 2.2 X =0 , Y =-3 --------> (X -4 +1)  ----- 2 rounds
            return 2;
    }
    else
        return 0;
}

int main()
{
    int t;

    int n1, n2;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n1 >> n2;
        cout << solve(n1, n2) << "\n";
    }
    return 0;
}