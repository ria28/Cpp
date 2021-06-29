#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    vector<int> row(n);
    vector<int> col(m);
    for (int i = 0; i < n; i++)
    {
        int row_and = 1;
        for (int j = 0; j < m; j++)
        {
            int ele;
            cin >> ele;
            b[i][j] = ele;
            row_and = row_and & ele;
        }
        row[i] = row_and;
    }

    for (int i = 0; i < m; i++)
    {
        int col_and = 1;
        for (int j = 0; j < n; j++)
        {

            col_and = col_and & b[j][i];
        }
        col[i] = col_and;
    }

    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] && col[j])
            {
                a[i][j] = 1;
            }
        }
    }

    row.resize(n, 0);
    col.resize(m, 0);
    for (int i = 0; i < n; i++)
    {
        int row_or = 0;
        for (int j = 0; j < m; j++)
        {
            row_or = row_or | a[i][j];
        }
        row[i] = row_or;
    }

    for (int i = 0; i < m; i++)
    {
        int col_or = 0;
        for (int j = 0; j < n; j++)
        {
            col_or = col_or | a[j][i];
        }
        col[i] = col_or;
    }

    // for(int i =0;i<m;i++)
    // cout<<col[i]<<" ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 0 && col[j] == 0)
            {
                if (b[i][j] != 0)
                {
                    // cout<<i<<j<<"<--";
                    cout << "NO";
                    return 0;
                }
            }
            else if (!row[i] || !col[j])
            {
                if (b[i][j] != 1)
                {
                    cout << "NO";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// ANOTHER SOLUTION

// Assign all aij (1 ≤ i ≤ m, 1 ≤ j ≤ n) equals to 1.
// If some bij = 0, then do assignments: aik = atj = 0 (1 ≤ k ≤ n, 1 ≤ t ≤ m) (that means, assign all elements in row i and column j of matrix a to 0).
// Then we have matrix a which need to find. Just check whether from matrix a, can we produce matrix b. If not, the answer is obviously "NO".




/* 

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> b(n, vector<int>(m));
    vector<int> row(n);
    vector<int> col(m);
    for (int i = 0; i < n; i++)
    {
        // int row_and = 1;
        for (int j = 0; j < m; j++)
        {
            int ele;
            cin >> ele;
            b[i][j] = ele;
            // row_and = row_and & ele;
        }
        // row[i] = row_and;
    }
 
    vector<vector<int>> a(n, vector<int>(m, 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[i][j] == 0)
            {
                for (int k = 0; k < n; k++)
                    a[k][j] = 0;
                for (int k = 0; k < m; k++)
                    a[i][k] = 0;
            }
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 1)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                if (b[i][j] != 1)
                {
                    cout << "NO";
                    return 0;
                }
            }
            else if(!row[i] && !col[j])
            {
                if(b[i][j] != 0)
                {
                    cout<<"NO";
                    return 0;
                }
                
            }
        }
    }
 
    cout<<"YES\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
 
    return 0;
}




 */