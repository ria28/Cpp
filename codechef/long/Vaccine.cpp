#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#define ll long long
using namespace std;

int main()
{
    int d1, v1, d2, v2;
    float p;
    cin >> d1 >> v1 >> d2 >> v2 >> p;
    int vac =0;
    int i;
    for(i =1;i<=10000;i++)
    {
        if(d1<=i)
        vac+=v1;
        if(d2<=i)
        vac += v2;
        if(vac>=p)
        break;
    }
    cout << i;

    return 0;
}