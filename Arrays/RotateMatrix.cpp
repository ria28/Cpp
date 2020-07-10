// geeksforgeeks.org/rotate-matrix-90-degree-without-using-extra-space-set-2/
// Rotate 90
#include <iostream>

using namespace std;

void transpose(int arr[4][4], int R, int C)
{
    for (int i = 0; i < R; i++)
    {
        for (int j = i; j < C; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
}

void reverse(int arr[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        int top = 0, bottom = 3;
        while (top < bottom)
        {
            swap(arr[top][i], arr[bottom][i]);
            top++;
            bottom--;
        }
    }
}
void rotate90(int arr[4][4])
{
    transpose(arr, 4, 4);
    reverse(arr);
}

void printMatrix(int arr[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<arr[i][j];
        }
        cout<<"\n";
    }
}
int main(int args, char **argc)
{
    int R = 4, C = 4;
    int arr[4][4] = {{1, 2, 3, 4},
                     {5, 6, 7, 8},
                     {9, 10, 11, 12},
                     {13, 14, 15, 16}};
    rotate90(arr);
    printMatrix(arr);
    return 0;
}