#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

// https://www.geeksforgeeks.org/permute-two-arrays-sum-every-pair-greater-equal-k/
// hackerrank

string PermutetwoArrays(int k, vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());

    for(long unsigned int i =0; i<A.size(); i++)
    {
        if(A[i]+B[i]<k)
            return "NO";
    }
    return "YES";
}

int main(int args, char **argc)
{
    // vector<int>a{2, 1, 3};
    // vector<int>b{7, 8, 9};
    // int k = 10;

    vector<int>a{1 ,5, 1, 4 ,4 ,2 ,7 ,1 ,2 ,2};
    vector<int>b{8 ,7 ,1 ,7 ,7 ,4 ,4 ,3 ,6 ,7};
    int k = 9;

    cout<<PermutetwoArrays(k,a,b);
}