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
#define vi vector<int>
#define vii vector<vector<int>>

// ASCII
// a - 97 ,   A - 65
// '0' - 48

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s ='s';
    cout<<s; // char print normally 
    cout<<s - 'a' +1 ;   // ith char in alphabets,,, (store all alphabets in vector (26)--> s-'a')
    
    cout<<int('1');   // 49 ascii 
    // char no -->no(int and perform calc);
    char one = '1';
    int n =one -'0';   
    cout<<"\n";
    cout<<n+10 <<" ,,,"<<one+10;  // normal , ascii of 1 + 10 = 59
    return 0;
}