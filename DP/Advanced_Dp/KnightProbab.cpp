#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
#define ll long long
using namespace std;
#define f_loop(i, s, e) for (int i = s; i < e; i++)
#define f_long(i, s, e) for (long long i = s; i < e; i++)
#define vi vector<double>
#define vii vector<vector<double>>

double knightProbability(int N, int K, int r, int c)
{
    vii mat(N, vi(N, 0));
    vii next_probab(N, vi(N, 0));
    int dir[8][8] = {{-2, 1}, {-2, -1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-1, -2}, {1, -2}};
    int fact = 8;
    mat[r][c] = 1;
    while (K--)
    {
        cout << K << "\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (mat[i][j] != 0)
                {
                    // cout << i << " " << j << "\n";
                    mat[i][j] = 0.0;
                    for (int dir_ = 0; dir_ < 8; dir_++)
                    {
                        int new_r = i + dir[dir_][0];
                        int new_c = j + dir[dir_][1];
                        // cout << new_r << " " << new_c << "\n";
                        if (new_r < 0 || new_r >= N || new_c < 0 || new_c >= N)
                            continue;
                        cout << new_r << " " << new_c << " ";
                        next_probab[new_r][new_c] += 1.0 / (fact);
                        cout << next_probab[new_r][new_c] << "\n";
                    }
                }
            }
        }
        fact *= fact;
        mat = next_probab;
    }

    double probab = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // cout << mat[i][j] << " ";
            if (mat[i][j] != 0)
            {
                probab += mat[i][j];
            }
        }
        cout << "\n";
    }
    cout << probab << " ";
    return probab;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    knightProbability(3, 2, 0, 0);
    return 0;
}