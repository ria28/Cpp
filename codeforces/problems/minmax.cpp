#include <iostream>
using namespace std;

void solve(int *arr, int m, int n)
{
    int minR[m],maxC[n];
    // minR.fill(INT32_MAX);
    // maxC.fill(INT32_MIN);

    fill(minR,minR+m,INT32_MAX);
    fill(maxC, maxC+n, INT32_MIN);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ele = *((arr+i*n) + j);
            if(minR[i]>ele)
                minR[i] =ele;
            // minR[i] = min(minR[i], ele);
            if(maxC[j]<ele)
                maxC[j]=ele;
            // maxC[j] = max(maxC[j], ele);
        }
    }

    for (int i = 0; i < m; i++)
    {
        if (minR[i] == maxC[i]){
            cout << minR[i];
            return;
        }
    }

    cout<<"404 not found";
}
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int m1, n1, m2, n2;
        cin >> m1 >> n1;
        int arr1[m1][n1];
        for (int i = 0; i < m1; i++)
        {
            for (int j = 0; j < n1; j++)
            {
                cin >> arr1[i][j];
            }
        }
        cin >> m2 >> n2;
        int arr2[m2][n2];
        for (int i = 0; i < m2; i++)
        {
            for (int j = 0; j < n2; j++)
            {
                cin >> arr2[i][j];
            }
        }

        if (m1 != m2 || n1 != n2)
        {
            cout << "Syntax error";
        }
        else
        {
            int arr[m1][n1];
            for (int i = 0; i < m1; i++)
            {
                for (int j = 0; j < n1; j++)
                {
                    arr[i][j] = arr1[i][j] + arr2[i][j];
                }
            }
            solve((int*)arr, m1, n1);
        }
    }
    return 0;
}